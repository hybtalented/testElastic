#pragma once

#include "ui_MainWindow.h"
#include<qbuffer.h>
#include<qthread.h>
class QNetworkAccessManager;
class QNetworkRequest;
class QNetworkReply;
typedef QVariantMap HttpHeader;
class httpRequest :public QThread {
	Q_OBJECT
public:
	httpRequest(QObject* parent = 0);
	~httpRequest();
	bool isRun() { return isrunning; }
	void run()override { QThread::exec(); }
	static QVariantMap request(const QString& url, const HttpHeader& header, const QByteArray& body, const QString& method = "GET");
public slots:
	void requestAsync(const QString& url, const HttpHeader& header, const QByteArray &body, const QString& method = "GET");
signals:
	void prograssChange(double up,double uptotal ,double down,double downtotal);
	void curlFinished(HttpHeader header, QByteArray body);
private:
	static HttpHeader ByteArray2HttpHeader(const QByteArray&);
	static void init();
	static void release();
	volatile bool isrunning{ false };
	
	static int _global_use_count;
};
class myWindow :public QMainWindow {
	Q_OBJECT
public:
	myWindow();
	~myWindow();
public slots:
	void request();
	void mimetypeChanged(QString);
	void methodchanged(QString);
	void isSyncChanged(bool);
	void reqheadChanged(int, int);
	void toJson();
	void urlChange(QUrl url1) {
		ui.webview->load(url1);
	}
	void toFormat();
	void curlFinished(HttpHeader header, QByteArray  body);
	void showDebugWindow();
signals:
	void AsynRequest(const QString& url, const HttpHeader& header, const QByteArray &body, const QString& method = "GET");
public:
	void resizeEvent(QResizeEvent *event) {
		ui.webview->repaint();
	}
private:
	Ui::MainWindow ui;
	QNetworkAccessManager * server;
	QNetworkRequest* requestbody;
	QString method;
	QByteArray array;
	QBuffer buffer;
	httpRequest * _request;
};