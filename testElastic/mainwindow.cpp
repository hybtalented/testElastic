#include"mainwindow.h"
#include <qnetworkaccessmanager.h>
#include <qnetworkreply.h>
#include<qjsondocument.h>
#include<qjsonobject.h>
#include<qregexp.h>
#include<qmetaobject.h>
#include<qmessagebox.h>
#include<qexception.h>
#include<curl/curl.h>
#include<qmimedatabase.h>
#include<QtWebEngine/QtWebEngine>
int httpRequest::_global_use_count = 0;
HttpHeader httpRequest::ByteArray2HttpHeader(const QByteArray &recvHeader)
{
	HttpHeader  headmap;
	QString strheader = recvHeader;
	qDebug() << strheader;
	auto headlist = strheader.split("\r\n");
	for (auto head : headlist) {
		auto headpair = head.split(":");
		QRegExp reg("^\\s*([^\\s]+)\\s*$");
		if (headpair.count() > 0 && headpair[0].replace(reg, "\\1").isEmpty())continue;
		switch (headpair.count()) {
		case 1:
			headmap.insert(headpair[0].replace(reg, "\\1"), "");
			break;
		case 2:
			headmap.insert(headpair[0].replace(reg, "\\1"), headpair[1].replace(reg, "\\1"));
			break;
		default:
			break;
		}
	}
	return headmap;
}
void httpRequest::init() {
	if (!_global_use_count++) {
		qDebug() << "global init curllib";
		curl_global_init(CURL_GLOBAL_ALL);
	}
}
void httpRequest::release() {
	if (!--_global_use_count) {
		qDebug() << "global clean up curl";
		curl_global_cleanup();
	}

}
/** libcurl接收数据
*/
static int read_buffer(void *ptr, size_t size, size_t nmemb, QByteArray *byte) {
	byte->append(QByteArray((const char*)ptr, size*nmemb));
	return nmemb;
}
static int setprograss(httpRequest* progress,
	double dltotal,
	double dlnow,
	double ultotal,
	double ulnow) {
	emit progress->prograssChange(ulnow, ultotal, dlnow, dltotal);
	return 0;
}
httpRequest::httpRequest(QObject* parent):QThread(parent)
{
	init();
}
QVariantMap httpRequest::request(const QString& url,const  HttpHeader& header, const QByteArray& body, const QString& method ) {
	init();
	QByteArray recvBody;
	QByteArray  recvHeader;
	auto curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &read_buffer);//接收函数
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &recvBody);  //接收数据
	curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, &read_buffer);//头接收函数
	curl_easy_setopt(curl, CURLOPT_HEADERDATA, &recvHeader);  //头接收数据
	//curl_easy_setopt(request, CURLOPT_READFUNCTION, write_buffer);//发送数据函数
	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.constData());
	//	curl_easy_setopt(request, CURLOPT_READDATA,&sendbuffer);  //发送数据
	curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, method.toUtf8().constData());
	curl_easy_setopt(curl, CURLOPT_NOPROGRESS, true);
	//发送http头
	struct curl_slist *headers = NULL; /* init to NULL is important */
	for (auto key : header.keys()) {
		headers = curl_slist_append(headers, QString("%1:%2").arg(key).arg(header[key].toString()).toUtf8().constData());
		qDebug() << headers->data;
	}
	/* pass our list of custom made headers */
	curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
	curl_easy_setopt(curl, CURLOPT_URL, url.toUtf8().constData());
	qDebug() << "start transmisson";
	CURLcode code = curl_easy_perform(curl); /* transfer http */
	qDebug() << "finish transmisson, return code:" << code;
	if (code != CURLE_OK) {
		recvHeader.append(QString("\r\nRequestError: %1").arg(curl_easy_strerror(code)));
	}
	curl_slist_free_all(headers); /* free the header list */
	curl_easy_cleanup(curl);
	QVariantMap map,headmap;
	map["head"] = ByteArray2HttpHeader(recvHeader);
	map["body"] = recvBody;
	release();
	return map;
}
void httpRequest::requestAsync(const QString &url, const HttpHeader& header,const QByteArray& body, const QString& method) {
	if (isrunning) {
		return ;
	}
	QByteArray recvBody;
	QByteArray  recvHeader;
	auto curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &read_buffer);//接收函数
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &recvBody);  //接收数据
	curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, &read_buffer);//头接收函数
	curl_easy_setopt(curl, CURLOPT_HEADERDATA, &recvHeader);  //头接收数据
	//curl_easy_setopt(request, CURLOPT_READFUNCTION, write_buffer);//发送数据函数
	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.constData());
	//	curl_easy_setopt(request, CURLOPT_READDATA,&sendbuffer);  //发送数据
	curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, method.toUtf8().constData());
	curl_easy_setopt(curl, CURLOPT_NOPROGRESS, false);
	curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, setprograss);
	curl_easy_setopt(curl, CURLOPT_PROGRESSDATA, this);
	//发送http头
	struct curl_slist *headers = NULL; /* init to NULL is important */
	for (auto key : header.keys()) {
		headers = curl_slist_append(headers, QString("%1:%2").arg(key).arg(header[key].toString()).toUtf8().constData());
	}
	/* pass our list of custom made headers */
	curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
	curl_easy_setopt(curl, CURLOPT_URL, url.toUtf8().constData());
	qDebug() << "start transmisson";
	auto code = curl_easy_perform(curl); /* transfer http */
	qDebug() << "finish transmisson code:" << code;
	curl_slist_free_all(headers); /* free the header list */
	curl_easy_cleanup(curl);
	emit curlFinished(ByteArray2HttpHeader(recvHeader), recvBody);
}
httpRequest::~httpRequest()
{
	release();
}
myWindow::myWindow() :buffer(&array) {
	qputenv("QTWEBENGINE_REMOTE_DEBUGGING", "5899");
	method = "GET";
	ui.setupUi(this);
	server = new QNetworkAccessManager();
	requestbody = new QNetworkRequest();
	_request = new httpRequest;
	Q_ASSERT(_request);
	QMimeDatabase db;
	for (auto str : db.allMimeTypes()) {
		ui.mimetype->addItem(str.name());
	}
	connect(this, SIGNAL(AsynRequest(const QString&, const HttpHeader&, const QByteArray &, const QString&)), _request, SLOT(requestAsync(const QString&, const HttpHeader&, const QByteArray &, const QString&)));
	QObject::connect(_request, &httpRequest::prograssChange, [=](double up,double uptotal,double down,double downtotal) {
		ui.progressBar->setValue(down / (downtotal+ uptotal) * 100);//传输进度
	});
	connect(_request, SIGNAL(curlFinished(HttpHeader , QByteArray)), this, SLOT(curlFinished(HttpHeader, QByteArray)));
	connect(ui.debug, SIGNAL(clicked()), this,SLOT(showDebugWindow()));
	connect(ui.refresh, &QPushButton::clicked, [=]() {
		qDebug() << "on refresh";
		ui.webview->reload();
	});
	connect(ui.changeview, &QPushButton::clicked, [=](bool checked) {
		if (checked) {
			ui.requestTab->hide();
			ui.toformat->hide();
			ui.label_3->hide();
			ui.label_2->hide();
			ui.issync->hide();
			ui.progressBar->hide();
			ui.method->hide();
			ui.changeview->setText(u8"还原");
		}
		else {
			ui.toformat->show();
			ui.label_3->show();
			ui.requestTab->show();
			ui.label_2->show();
			ui.issync->show();
			ui.method->show();
			ui.progressBar->show();
			ui.changeview->setText(u8"放大");
		}

	});

}
myWindow::~myWindow()
{
	curl_global_cleanup();
	server->deleteLater();
	if (_request) {
		delete _request;
	}
}

void myWindow::request() {
	HttpHeader header;
	for (int i = 0; i < ui.reqheader->rowCount() - 1; ++i) {
		if(!ui.reqheader->item(i, 0)->text().isEmpty())header.insert(ui.reqheader->item(i,0)->text(), ui.reqheader->item(i,1)->text());
	}
	qDebug() << "request: url:" << ui.url->text() << ",header:" << header << "method:"<<method;
	QString mimetype = "application/text";
	if (ui.issync->isChecked()) {
		auto result = httpRequest::request(ui.url->text(), header, ui.jsonbody->toPlainText().toUtf8(), method);
		curlFinished(result["head"].toMap(), result["body"].toByteArray());
	}
	else {
		if (_request->isRun()) {
			QMessageBox::information(this, u8"暂时无法请求", u8"上次请求尚未完成请稍后重试");
		}
		emit AsynRequest(ui.url->text(), header, ui.jsonbody->toPlainText().toUtf8(), method);
	}
}
void myWindow::mimetypeChanged(QString str)
{
	ui.webview->setContent(ui.response->toPlainText().toUtf8(), str, ui.url->text());
}
void myWindow::methodchanged(QString pmethod)
{
	qDebug() << u8"请求头改变:"<<pmethod;
	method = pmethod;
}

void myWindow::isSyncChanged(bool checked)
{
	if (checked) {
		ui.progressBar->hide();
	}
	else {
		ui.progressBar->show();
	}
}

void myWindow::reqheadChanged(int row, int col)
{
	if (ui.reqheader->item(row, 0)->text().isEmpty() && ui.reqheader->item(row, 1)->text().isEmpty()) {
		ui.reqheader->removeRow(row);
	}
	if (row + 1 == ui.reqheader->rowCount()) {
		ui.reqheader->setRowCount(ui.reqheader->rowCount()+1);
	}
	
}

void myWindow::toJson()
{
	QString str = QJsonDocument::fromJson(ui.response->toPlainText().toUtf8()).toJson(QJsonDocument::Indented);
	if (!str.isEmpty()) {
		ui.response->setPlainText(str);
	}
}
void myWindow::toFormat()
{
	QString current_text = ui.jsonbody->toPlainText();
	QJsonDocument doc=QJsonDocument::fromJson(current_text.toUtf8());
	if (!doc.isNull()) {
		ui.jsonbody->setText(QString(doc.toJson()));
	}
}

void myWindow::curlFinished(HttpHeader header, QByteArray body)
{
	auto respheader = header;
		auto keys = respheader.keys();
		ui.respheader->setRowCount(keys.count());
		for (int i = 0; i < keys.count(); ++i) {
			auto key = keys[i];
			QString temp = key;
			if (key.indexOf("Content-Type", Qt::CaseInsensitive) != -1) {
				QString minetype = respheader[key].toString();
			}
			auto item0 = new QTableWidgetItem(key), item1 = new QTableWidgetItem(respheader[key].toString());
			qDebug() << key << respheader[key].toString();
			ui.respheader->setItem(i, 0, item0);
			ui.respheader->setItem(i, 1, item1);
	}
	QMimeDatabase db;
	QByteArray array = body;
	QString mimetype = db.mimeTypeForData(array).name();
	ui.mimetype->setCurrentText(mimetype);
	ui.response->setPlainText(array);
	ui.webview->page()->setContent(array, mimetype,ui.url->text());
	ui.webview->showMaximized();
}

void myWindow::showDebugWindow()
{
	static QWidget * widget=nullptr;
	static QWebEngineView* webview = nullptr;
	if (!widget) {
		qDebug() << "debug view created";
		widget =new  QWidget;
		webview = new QWebEngineView(widget);
		widget->showMaximized();
		QGridLayout * layout = new QGridLayout(widget);
		layout->addWidget(webview);
		widget->setLayout(layout);
		webview->setWindowTitle("调试窗口");
		widget->setMinimumSize(300, 400);
		connect(widget, &QWidget::destroyed, [=] {
			qDebug() << "debug view destroyed";
			webview = nullptr;
		});
		connect(this, &QWidget::destroyed, widget,[=] {
			widget->close();
		});
	}
	widget->show();
	webview->page()->load(QUrl(QString("http://localhost:5899")));
}

