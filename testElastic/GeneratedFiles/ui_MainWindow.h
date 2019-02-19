/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QPushButton *tojson;
    QLabel *label_4;
    QLabel *label_2;
    QTextEdit *jsonbody;
    QLabel *label;
    QPushButton *requestbtn;
    QLabel *label_5;
    QPushButton *toformat;
    QProgressBar *progressBar;
    QComboBox *method;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_3;
    QTextEdit *header;
    QWidget *tab_2;
    QGridLayout *gridLayout_2;
    QTextEdit *response;
    QLineEdit *url;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/elastic-logo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 1, 1, 1);

        tojson = new QPushButton(centralwidget);
        tojson->setObjectName(QStringLiteral("tojson"));

        gridLayout->addWidget(tojson, 5, 4, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 5, 1, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        jsonbody = new QTextEdit(centralwidget);
        jsonbody->setObjectName(QStringLiteral("jsonbody"));

        gridLayout->addWidget(jsonbody, 3, 1, 1, 3);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        requestbtn = new QPushButton(centralwidget);
        requestbtn->setObjectName(QStringLiteral("requestbtn"));
        requestbtn->setCheckable(false);

        gridLayout->addWidget(requestbtn, 0, 4, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 4, 1, 1, 1);

        toformat = new QPushButton(centralwidget);
        toformat->setObjectName(QStringLiteral("toformat"));

        gridLayout->addWidget(toformat, 2, 4, 1, 1);

        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        gridLayout->addWidget(progressBar, 4, 2, 1, 2);

        method = new QComboBox(centralwidget);
        method->addItem(QString());
        method->addItem(QString());
        method->addItem(QString());
        method->addItem(QString());
        method->addItem(QString());
        method->addItem(QString());
        method->setObjectName(QStringLiteral("method"));

        gridLayout->addWidget(method, 1, 2, 1, 1);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_3 = new QGridLayout(tab);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        header = new QTextEdit(tab);
        header->setObjectName(QStringLiteral("header"));

        gridLayout_3->addWidget(header, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_2 = new QGridLayout(tab_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        response = new QTextEdit(tab_2);
        response->setObjectName(QStringLiteral("response"));
        response->setReadOnly(true);

        gridLayout_2->addWidget(response, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 6, 1, 1, 2);

        url = new QLineEdit(centralwidget);
        url->setObjectName(QStringLiteral("url"));

        gridLayout->addWidget(url, 0, 2, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(method, SIGNAL(currentIndexChanged(QString)), MainWindow, SLOT(methodchanged(QString)));
        QObject::connect(url, SIGNAL(textChanged(QString)), MainWindow, SLOT(urlchanged(QString)));
        QObject::connect(requestbtn, SIGNAL(clicked()), MainWindow, SLOT(request()));
        QObject::connect(tojson, SIGNAL(clicked()), MainWindow, SLOT(toJson()));
        QObject::connect(toformat, SIGNAL(clicked()), MainWindow, SLOT(toFormat()));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\346\265\213\350\257\225elasticsearch", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "JSON\350\257\267\346\261\202\344\275\223:", nullptr));
        tojson->setText(QApplication::translate("MainWindow", "JSON\346\240\274\345\274\217\345\214\226(Ctrl+F)", nullptr));
#ifndef QT_NO_SHORTCUT
        tojson->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", nullptr));
#endif // QT_NO_SHORTCUT
        label_4->setText(QApplication::translate("MainWindow", "\346\234\215\345\212\241\345\231\250\350\277\224\345\233\236\347\273\223\346\236\234:", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\350\257\267\346\261\202\346\226\271\346\263\225\357\274\232", nullptr));
        jsonbody->setPlaceholderText(QApplication::translate("MainWindow", "\350\257\246\346\203\205\350\247\201 <a href=\"https://www.elastic.co/guide/cn/elasticsearch/guide/current/index.html\"></a>", nullptr));
        label->setText(QApplication::translate("MainWindow", "\350\257\267\346\261\202url\357\274\232", nullptr));
        requestbtn->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\350\257\267\346\261\202(Ctrl+D)", nullptr));
#ifndef QT_NO_SHORTCUT
        requestbtn->setShortcut(QApplication::translate("MainWindow", "Ctrl+D", nullptr));
#endif // QT_NO_SHORTCUT
        label_5->setText(QApplication::translate("MainWindow", "\344\274\240\350\276\223\350\277\233\345\272\246:", nullptr));
        toformat->setText(QApplication::translate("MainWindow", "\346\240\274\345\274\217\345\214\226(Ctrl+S)", nullptr));
#ifndef QT_NO_SHORTCUT
        toformat->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        method->setItemText(0, QApplication::translate("MainWindow", "GET", nullptr));
        method->setItemText(1, QApplication::translate("MainWindow", "POST", nullptr));
        method->setItemText(2, QApplication::translate("MainWindow", "PUT", nullptr));
        method->setItemText(3, QApplication::translate("MainWindow", "DELETE", nullptr));
        method->setItemText(4, QApplication::translate("MainWindow", "HEAD", nullptr));
        method->setItemText(5, QApplication::translate("MainWindow", "OTHER", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "http header", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "http body", nullptr));
        url->setPlaceholderText(QApplication::translate("MainWindow", "\345\246\202 192.168.123.11:8088/index/type/id", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
