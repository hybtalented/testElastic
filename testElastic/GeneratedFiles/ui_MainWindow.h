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
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *requestbtn;
    QLineEdit *url;
    QPushButton *tojson;
    QComboBox *method;
    QLabel *label_4;
    QLabel *label;
    QCheckBox *issync;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *toformat;
    QTabWidget *requestTab;
    QWidget *tab_3;
    QGridLayout *gridLayout_5;
    QTableWidget *reqheader;
    QWidget *tab_4;
    QGridLayout *gridLayout_4;
    QTextEdit *jsonbody;
    QLabel *label_6;
    QProgressBar *progressBar;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_3;
    QTableWidget *respheader;
    QWidget *tab_2;
    QGridLayout *gridLayout_2;
    QTextEdit *response;
    QWidget *tab_5;
    QGridLayout *gridLayout_6;
    QWebEngineView *webview;
    QComboBox *mimetype;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *refresh;
    QPushButton *debug;
    QPushButton *changeview;
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
        requestbtn = new QPushButton(centralwidget);
        requestbtn->setObjectName(QStringLiteral("requestbtn"));
        requestbtn->setCheckable(false);

        gridLayout->addWidget(requestbtn, 0, 5, 1, 1);

        url = new QLineEdit(centralwidget);
        url->setObjectName(QStringLiteral("url"));

        gridLayout->addWidget(url, 0, 3, 1, 1);

        tojson = new QPushButton(centralwidget);
        tojson->setObjectName(QStringLiteral("tojson"));

        gridLayout->addWidget(tojson, 6, 5, 1, 1);

        method = new QComboBox(centralwidget);
        method->addItem(QString());
        method->addItem(QString());
        method->addItem(QString());
        method->addItem(QString());
        method->addItem(QString());
        method->addItem(QString());
        method->setObjectName(QStringLiteral("method"));

        gridLayout->addWidget(method, 1, 3, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 6, 1, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        issync = new QCheckBox(centralwidget);
        issync->setObjectName(QStringLiteral("issync"));
        issync->setChecked(false);

        gridLayout->addWidget(issync, 1, 5, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 1, 1, 1);

        toformat = new QPushButton(centralwidget);
        toformat->setObjectName(QStringLiteral("toformat"));

        gridLayout->addWidget(toformat, 2, 5, 1, 1);

        requestTab = new QTabWidget(centralwidget);
        requestTab->setObjectName(QStringLiteral("requestTab"));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_5 = new QGridLayout(tab_3);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        reqheader = new QTableWidget(tab_3);
        if (reqheader->columnCount() < 2)
            reqheader->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        reqheader->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        reqheader->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (reqheader->rowCount() < 2)
            reqheader->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        reqheader->setVerticalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        reqheader->setVerticalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        reqheader->setItem(0, 0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        reqheader->setItem(0, 1, __qtablewidgetitem5);
        reqheader->setObjectName(QStringLiteral("reqheader"));

        gridLayout_5->addWidget(reqheader, 0, 0, 1, 1);

        requestTab->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        gridLayout_4 = new QGridLayout(tab_4);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        jsonbody = new QTextEdit(tab_4);
        jsonbody->setObjectName(QStringLiteral("jsonbody"));

        gridLayout_4->addWidget(jsonbody, 0, 0, 1, 1);

        requestTab->addTab(tab_4, QString());

        gridLayout->addWidget(requestTab, 3, 1, 1, 3);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 6, 2, 1, 1);

        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        gridLayout->addWidget(progressBar, 4, 1, 1, 4);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_3 = new QGridLayout(tab);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        respheader = new QTableWidget(tab);
        if (respheader->columnCount() < 2)
            respheader->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        respheader->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        respheader->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        respheader->setObjectName(QStringLiteral("respheader"));
        respheader->setEditTriggers(QAbstractItemView::NoEditTriggers);

        gridLayout_3->addWidget(respheader, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_2 = new QGridLayout(tab_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        response = new QTextEdit(tab_2);
        response->setObjectName(QStringLiteral("response"));

        gridLayout_2->addWidget(response, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        gridLayout_6 = new QGridLayout(tab_5);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        webview = new QWebEngineView(tab_5);
        webview->setObjectName(QStringLiteral("webview"));
        webview->setUrl(QUrl(QStringLiteral("about:blank")));

        gridLayout_6->addWidget(webview, 0, 0, 1, 1);

        tabWidget->addTab(tab_5, QString());

        gridLayout->addWidget(tabWidget, 7, 1, 1, 3);

        mimetype = new QComboBox(centralwidget);
        mimetype->setObjectName(QStringLiteral("mimetype"));
        mimetype->setEditable(false);

        gridLayout->addWidget(mimetype, 6, 3, 1, 1);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setLayoutDirection(Qt::LeftToRight);
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        refresh = new QPushButton(widget);
        refresh->setObjectName(QStringLiteral("refresh"));

        verticalLayout->addWidget(refresh);

        debug = new QPushButton(widget);
        debug->setObjectName(QStringLiteral("debug"));

        verticalLayout->addWidget(debug);

        changeview = new QPushButton(widget);
        changeview->setObjectName(QStringLiteral("changeview"));
        changeview->setCheckable(true);

        verticalLayout->addWidget(changeview);


        gridLayout->addWidget(widget, 7, 5, 1, 1, Qt::AlignTop);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(method, SIGNAL(currentIndexChanged(QString)), MainWindow, SLOT(methodchanged(QString)));
        QObject::connect(requestbtn, SIGNAL(clicked()), MainWindow, SLOT(request()));
        QObject::connect(tojson, SIGNAL(clicked()), MainWindow, SLOT(toJson()));
        QObject::connect(toformat, SIGNAL(clicked()), MainWindow, SLOT(toFormat()));
        QObject::connect(issync, SIGNAL(clicked(bool)), MainWindow, SLOT(isSyncChanged(bool)));
        QObject::connect(reqheader, SIGNAL(cellChanged(int,int)), MainWindow, SLOT(reqheadChanged(int,int)));
        QObject::connect(webview, SIGNAL(urlChanged(QUrl)), MainWindow, SLOT(urlChange(QUrl)));
        QObject::connect(mimetype, SIGNAL(currentIndexChanged(QString)), MainWindow, SLOT(mimetypeChanged(QString)));

        requestTab->setCurrentIndex(1);
        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\346\265\213\350\257\225elasticsearch", nullptr));
        requestbtn->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\350\257\267\346\261\202(Ctrl+D)", nullptr));
#ifndef QT_NO_SHORTCUT
        requestbtn->setShortcut(QApplication::translate("MainWindow", "Ctrl+D", nullptr));
#endif // QT_NO_SHORTCUT
        url->setPlaceholderText(QApplication::translate("MainWindow", "\345\246\202 192.168.123.11:8088/index/type/id", nullptr));
        tojson->setText(QApplication::translate("MainWindow", "JSON\346\240\274\345\274\217\345\214\226(Ctrl+F)", nullptr));
#ifndef QT_NO_SHORTCUT
        tojson->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", nullptr));
#endif // QT_NO_SHORTCUT
        method->setItemText(0, QApplication::translate("MainWindow", "GET", nullptr));
        method->setItemText(1, QApplication::translate("MainWindow", "POST", nullptr));
        method->setItemText(2, QApplication::translate("MainWindow", "PUT", nullptr));
        method->setItemText(3, QApplication::translate("MainWindow", "DELETE", nullptr));
        method->setItemText(4, QApplication::translate("MainWindow", "HEAD", nullptr));
        method->setItemText(5, QApplication::translate("MainWindow", "OTHER", nullptr));

        label_4->setText(QApplication::translate("MainWindow", "\346\234\215\345\212\241\345\231\250\350\277\224\345\233\236\347\273\223\346\236\234:", nullptr));
        label->setText(QApplication::translate("MainWindow", "\350\257\267\346\261\202url\357\274\232", nullptr));
        issync->setText(QApplication::translate("MainWindow", "\346\230\257\345\220\246\345\220\214\346\255\245\350\257\267\346\261\202", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\350\257\267\346\261\202\346\226\271\346\263\225\357\274\232", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "JSON\350\257\267\346\261\202\344\275\223", nullptr));
        toformat->setText(QApplication::translate("MainWindow", "\346\240\274\345\274\217\345\214\226(Ctrl+S)", nullptr));
#ifndef QT_NO_SHORTCUT
        toformat->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        QTableWidgetItem *___qtablewidgetitem = reqheader->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "key", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = reqheader->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "value", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = reqheader->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = reqheader->verticalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "2", nullptr));

        const bool __sortingEnabled = reqheader->isSortingEnabled();
        reqheader->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem4 = reqheader->item(0, 0);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Content-Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = reqheader->item(0, 1);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "application/json;charset=UTF-8", nullptr));
        reqheader->setSortingEnabled(__sortingEnabled);

        requestTab->setTabText(requestTab->indexOf(tab_3), QApplication::translate("MainWindow", "\350\257\267\346\261\202\345\244\264", nullptr));
        jsonbody->setPlaceholderText(QApplication::translate("MainWindow", "\350\257\246\346\203\205\350\247\201 <a href=\"https://www.elastic.co/guide/cn/elasticsearch/guide/current/index.html\"></a>", nullptr));
        requestTab->setTabText(requestTab->indexOf(tab_4), QApplication::translate("MainWindow", "JSON\350\257\267\346\261\202\344\275\223", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "MIME\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = respheader->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "key", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = respheader->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "value", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\350\277\224\345\233\236\345\244\264", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\350\277\224\345\233\236\344\275\223", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "web\346\265\217\350\247\210\345\231\250", nullptr));
        refresh->setText(QApplication::translate("MainWindow", "\345\210\267\346\226\260\351\241\265\351\235\242", nullptr));
        debug->setText(QApplication::translate("MainWindow", "\350\260\203\350\257\225\347\252\227\345\217\243", nullptr));
        changeview->setText(QApplication::translate("MainWindow", "\346\224\276\345\244\247", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
