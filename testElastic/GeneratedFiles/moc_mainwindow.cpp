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
struct qt_meta_stringdata_httpRequest_t {
    QByteArrayData data[14];
    char stringdata0[114];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_httpRequest_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_httpRequest_t qt_meta_stringdata_httpRequest = {
    {
QT_MOC_LITERAL(0, 0, 11), // "httpRequest"
QT_MOC_LITERAL(1, 12, 14), // "prograssChange"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 2), // "up"
QT_MOC_LITERAL(4, 31, 7), // "uptotal"
QT_MOC_LITERAL(5, 39, 4), // "down"
QT_MOC_LITERAL(6, 44, 9), // "downtotal"
QT_MOC_LITERAL(7, 54, 12), // "curlFinished"
QT_MOC_LITERAL(8, 67, 10), // "HttpHeader"
QT_MOC_LITERAL(9, 78, 6), // "header"
QT_MOC_LITERAL(10, 85, 4), // "body"
QT_MOC_LITERAL(11, 90, 12), // "requestAsync"
QT_MOC_LITERAL(12, 103, 3), // "url"
QT_MOC_LITERAL(13, 107, 6) // "method"

    },
    "httpRequest\0prograssChange\0\0up\0uptotal\0"
    "down\0downtotal\0curlFinished\0HttpHeader\0"
    "header\0body\0requestAsync\0url\0method"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_httpRequest[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   34,    2, 0x06 /* Public */,
       7,    2,   43,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    4,   48,    2, 0x0a /* Public */,
      11,    3,   57,    2, 0x2a /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double,    3,    4,    5,    6,
    QMetaType::Void, 0x80000000 | 8, QMetaType::QByteArray,    9,   10,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 8, QMetaType::QByteArray, QMetaType::QString,   12,    9,   10,   13,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 8, QMetaType::QByteArray,   12,    9,   10,

       0        // eod
};

void httpRequest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        httpRequest *_t = static_cast<httpRequest *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->prograssChange((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 1: _t->curlFinished((*reinterpret_cast< HttpHeader(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 2: _t->requestAsync((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const HttpHeader(*)>(_a[2])),(*reinterpret_cast< const QByteArray(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 3: _t->requestAsync((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const HttpHeader(*)>(_a[2])),(*reinterpret_cast< const QByteArray(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (httpRequest::*)(double , double , double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&httpRequest::prograssChange)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (httpRequest::*)(HttpHeader , QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&httpRequest::curlFinished)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject httpRequest::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_httpRequest.data,
      qt_meta_data_httpRequest,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *httpRequest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *httpRequest::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_httpRequest.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int httpRequest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void httpRequest::prograssChange(double _t1, double _t2, double _t3, double _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void httpRequest::curlFinished(HttpHeader _t1, QByteArray _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_myWindow_t {
    QByteArrayData data[19];
    char stringdata0[183];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_myWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_myWindow_t qt_meta_stringdata_myWindow = {
    {
QT_MOC_LITERAL(0, 0, 8), // "myWindow"
QT_MOC_LITERAL(1, 9, 11), // "AsynRequest"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 3), // "url"
QT_MOC_LITERAL(4, 26, 10), // "HttpHeader"
QT_MOC_LITERAL(5, 37, 6), // "header"
QT_MOC_LITERAL(6, 44, 4), // "body"
QT_MOC_LITERAL(7, 49, 6), // "method"
QT_MOC_LITERAL(8, 56, 7), // "request"
QT_MOC_LITERAL(9, 64, 15), // "mimetypeChanged"
QT_MOC_LITERAL(10, 80, 13), // "methodchanged"
QT_MOC_LITERAL(11, 94, 13), // "isSyncChanged"
QT_MOC_LITERAL(12, 108, 14), // "reqheadChanged"
QT_MOC_LITERAL(13, 123, 6), // "toJson"
QT_MOC_LITERAL(14, 130, 9), // "urlChange"
QT_MOC_LITERAL(15, 140, 4), // "url1"
QT_MOC_LITERAL(16, 145, 8), // "toFormat"
QT_MOC_LITERAL(17, 154, 12), // "curlFinished"
QT_MOC_LITERAL(18, 167, 15) // "showDebugWindow"

    },
    "myWindow\0AsynRequest\0\0url\0HttpHeader\0"
    "header\0body\0method\0request\0mimetypeChanged\0"
    "methodchanged\0isSyncChanged\0reqheadChanged\0"
    "toJson\0urlChange\0url1\0toFormat\0"
    "curlFinished\0showDebugWindow"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_myWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   74,    2, 0x06 /* Public */,
       1,    3,   83,    2, 0x26 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   90,    2, 0x0a /* Public */,
       9,    1,   91,    2, 0x0a /* Public */,
      10,    1,   94,    2, 0x0a /* Public */,
      11,    1,   97,    2, 0x0a /* Public */,
      12,    2,  100,    2, 0x0a /* Public */,
      13,    0,  105,    2, 0x0a /* Public */,
      14,    1,  106,    2, 0x0a /* Public */,
      16,    0,  109,    2, 0x0a /* Public */,
      17,    2,  110,    2, 0x0a /* Public */,
      18,    0,  115,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4, QMetaType::QByteArray, QMetaType::QString,    3,    5,    6,    7,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4, QMetaType::QByteArray,    3,    5,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QUrl,   15,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, QMetaType::QByteArray,    5,    6,
    QMetaType::Void,

       0        // eod
};

void myWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        myWindow *_t = static_cast<myWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->AsynRequest((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const HttpHeader(*)>(_a[2])),(*reinterpret_cast< const QByteArray(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 1: _t->AsynRequest((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const HttpHeader(*)>(_a[2])),(*reinterpret_cast< const QByteArray(*)>(_a[3]))); break;
        case 2: _t->request(); break;
        case 3: _t->mimetypeChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->methodchanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->isSyncChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->reqheadChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->toJson(); break;
        case 8: _t->urlChange((*reinterpret_cast< QUrl(*)>(_a[1]))); break;
        case 9: _t->toFormat(); break;
        case 10: _t->curlFinished((*reinterpret_cast< HttpHeader(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 11: _t->showDebugWindow(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (myWindow::*)(const QString & , const HttpHeader & , const QByteArray & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&myWindow::AsynRequest)) {
                *result = 0;
                return;
            }
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
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void myWindow::AsynRequest(const QString & _t1, const HttpHeader & _t2, const QByteArray & _t3, const QString & _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
