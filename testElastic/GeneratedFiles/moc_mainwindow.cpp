/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_myWindow_t {
    QByteArrayData data[10];
    char stringdata0[89];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_myWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_myWindow_t qt_meta_stringdata_myWindow = {
    {
QT_MOC_LITERAL(0, 0, 8), // "myWindow"
QT_MOC_LITERAL(1, 9, 7), // "request"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 10), // "urlchanged"
QT_MOC_LITERAL(4, 29, 13), // "methodchanged"
QT_MOC_LITERAL(5, 43, 8), // "finished"
QT_MOC_LITERAL(6, 52, 14), // "QNetworkReply*"
QT_MOC_LITERAL(7, 67, 5), // "reply"
QT_MOC_LITERAL(8, 73, 6), // "toJson"
QT_MOC_LITERAL(9, 80, 8) // "toFormat"

    },
    "myWindow\0request\0\0urlchanged\0methodchanged\0"
    "finished\0QNetworkReply*\0reply\0toJson\0"
    "toFormat"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_myWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    1,   45,    2, 0x0a /* Public */,
       4,    1,   48,    2, 0x0a /* Public */,
       5,    1,   51,    2, 0x0a /* Public */,
       8,    0,   54,    2, 0x0a /* Public */,
       9,    0,   55,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void myWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        myWindow *_t = static_cast<myWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->request(); break;
        case 1: _t->urlchanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->methodchanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->finished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 4: _t->toJson(); break;
        case 5: _t->toFormat(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject myWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_myWindow.data,
      qt_meta_data_myWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *myWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *myWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_myWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int myWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
