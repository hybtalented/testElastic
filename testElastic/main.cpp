#include<qapplication.h>
#include<qdir.h>
#include"mainwindow.h"
using namespace std;
#define REMOTE_IP "47.110.71.66"
#define REMOTE_PORT 5601

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QString dir = QApplication::applicationDirPath();
	QDir::setCurrent(dir);
	myWindow window;
	window.show();
	return a.exec();
}
