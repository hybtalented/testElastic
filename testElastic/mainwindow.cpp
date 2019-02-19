#include"mainwindow.h"
#include <qnetworkaccessmanager.h>
#include <qnetworkreply.h>
#include<qjsondocument.h>
#include<qregexp.h>
#include<qmetaobject.h>
#include<qmessagebox.h>
#include<qexception.h>
#include<curl/curl.h>
QNetworkAccessManager::Operation getMethod(const QString&method) {

	if (method.indexOf("delete", Qt::CaseInsensitive) != -1) {
		return QNetworkAccessManager::DeleteOperation;
	}
	if (method.indexOf("get", Qt::CaseInsensitive) != -1) {
		return QNetworkAccessManager::GetOperation;
	}
	if (method.indexOf("put", Qt::CaseInsensitive) != -1) {
		return QNetworkAccessManager::PutOperation;
	}
	if (method.indexOf("post", Qt::CaseInsensitive) != -1) {
		return QNetworkAccessManager::PostOperation;
	}
	if (method.indexOf("head", Qt::CaseInsensitive) != -1) {
		return QNetworkAccessManager::HeadOperation;
	}
	return QNetworkAccessManager::CustomOperation;
}
myWindow::myWindow():buffer(&array) {
	method = "GET";
	ui.setupUi(this);
	server = new QNetworkAccessManager();
	requestbody = new QNetworkRequest();
	connect(server, SIGNAL(finished(QNetworkReply *)), this, SLOT(finished(QNetworkReply *)));
	curl_global_init(CURL_GLOBAL_ALL);
}
myWindow::~myWindow()
{
	curl_global_cleanup();
	server->deleteLater();
}
/** libcurl��������
*/
static int read_buffer(void *ptr, size_t size, size_t nmemb, QTextEdit *stream) {
	
	stream->setText(stream->toPlainText() + QByteArray((const char*)ptr, size*nmemb));
	return nmemb;
}
/** libcurl ��������
*/
static size_t write_buffer(void *ptr, size_t size, size_t nmemb, QBuffer *stream) {
	if (!stream) {
		stream->open(QIODevice::WriteOnly);
	}
		qDebug() << QString("read data count: %2, sizep:%3").arg(size).arg(nmemb);
	if (stream->atEnd()) {
		stream->close();
		return 0;
	}
	auto data = stream->read(size*nmemb);
	memcpy(ptr, data.constData(), data.size());
	qDebug() << QString("read data count: %2, sizep:%3 ,  data:%4, datasize %5").arg(size).arg(nmemb).arg(QString(data)).arg(data.size());
	return data.size();
}
static int setprograss(QProgressBar* progress,
	double dltotal,
	double dlnow,
	double ultotal,
	double ulnow) {
	progress->setValue((dlnow + ulnow) / (dltotal + ultotal) * 100);
	return 0;
}
void myWindow::request() {
	if (url.isEmpty()) {
		QMessageBox::warning(this, u8"����url����", u8"����url����");
		return;
	}
	ui.response->setText("");
	ui.header->setText("");
	ui.progressBar->setValue(0);
	auto request = curl_easy_init(); // ��ʼ��һ������
	QByteArray sendbody = ui.jsonbody->toPlainText().toUtf8(); //����json��
	QBuffer sendbuffer(&sendbody);
	curl_easy_setopt(request, CURLOPT_WRITEFUNCTION, read_buffer);//���պ���
	curl_easy_setopt(request, CURLOPT_WRITEDATA, ui.response);  //��������
	curl_easy_setopt(request, CURLOPT_HEADERFUNCTION, read_buffer);//ͷ���պ���
	curl_easy_setopt(request, CURLOPT_HEADERDATA, ui.header);  //ͷ��������
	//curl_easy_setopt(request, CURLOPT_READFUNCTION, write_buffer);//�������ݺ���
	curl_easy_setopt(request, CURLOPT_POSTFIELDS,sendbody.constData());
//	curl_easy_setopt(request, CURLOPT_READDATA,&sendbuffer);  //��������
	curl_easy_setopt(request, CURLOPT_CUSTOMREQUEST, method.toUtf8().constData());
	curl_easy_setopt(request, CURLOPT_NOPROGRESS,false);
	curl_easy_setopt(request, CURLOPT_PROGRESSFUNCTION, setprograss);
	curl_easy_setopt(request, CURLOPT_PROGRESSDATA,ui.progressBar);
	//����httpͷ
	struct curl_slist *headers = NULL; /* init to NULL is important */
	headers = curl_slist_append(headers, "Content-Type:application/json;charset=UTF-8");
	/* pass our list of custom made headers */
	curl_easy_setopt(request, CURLOPT_HTTPHEADER, headers);
	curl_easy_setopt(request, CURLOPT_URL, url.toUtf8().constData());
	qDebug() << "start transmisson";
	auto code = curl_easy_perform(request); /* transfer http */
	qDebug() << "finish transmisson code:" << code;
	curl_slist_free_all(headers); /* free the header list */
	curl_easy_cleanup(request);
}
void myWindow::urlchanged(QString cmdstr)
{
	QRegExp cmdreg("^\\s*(https?://)?(\\d{1,3}.\\d{1,3}.\\d{1,3}.\\d{1,3}|[\\w\\.]+):(\\d+)(/[\\w\\d/\\?&\\.]* )\\s*$", Qt::CaseInsensitive);
	if (cmdreg.indexIn(cmdstr) != -1) {
		url = ui.url->text();
	}
	else {
		if(!url.isEmpty()) ui.url->setText(url);
		qDebug() << u8"����url����" << cmdstr;
	}
}
void myWindow::methodchanged(QString pmethod)
{
	qDebug() << u8"����ͷ�ı�:"<<pmethod;
	method = pmethod;
}

void myWindow::finished(QNetworkReply *reply)
{
	try {
		qDebug()<< array;
		QMetaEnum error = QMetaEnum::fromType<QNetworkReply::NetworkError>();
		QString errstr = QString("code:%3\n status: %1;\n message: %2\n").arg(error.valueToKey(reply->error())).arg(reply->errorString()).arg(reply->error());
		if (reply->error() == QNetworkReply::NoError) {
			ui.response->setPlainText(reply->readAll());
		}
		else {
			errstr += QString("body: %1").arg(QString(reply->readAll()));
			QMessageBox::critical(this, u8"�������", errstr, u8"ȷ��");
		}
	}
	catch (QException ex) {
		qDebug()<<ex.what();
	}
	reply->deleteLater();
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
