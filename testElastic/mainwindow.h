#pragma once

#include "ui_MainWindow.h"
#include<qbuffer.h>
class QNetworkAccessManager;
class QNetworkRequest;
class QNetworkReply;
class myWindow :public QMainWindow {
	Q_OBJECT
public:
	myWindow();
	~myWindow();
public slots:
	void request();
	void urlchanged(QString);
	void methodchanged(QString);
	void finished(QNetworkReply *reply);
	void toJson();
	void toFormat();
private:
	QString url;
	Ui::MainWindow ui;
	QNetworkAccessManager * server;
	QNetworkRequest* requestbody;
	QString method;
	QByteArray array;
	QBuffer buffer;
};