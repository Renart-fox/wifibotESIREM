/****************************************************************************
** Meta object code from reading C++ file 'tcpclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../wifibotKevinBaptiste/tcpclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TCPClient_t {
    QByteArrayData data[15];
    char stringdata0[151];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TCPClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TCPClient_t qt_meta_stringdata_TCPClient = {
    {
QT_MOC_LITERAL(0, 0, 9), // "TCPClient"
QT_MOC_LITERAL(1, 10, 16), // "reportConnection"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 6), // "status"
QT_MOC_LITERAL(4, 35, 9), // "signalBat"
QT_MOC_LITERAL(5, 45, 4), // "valB"
QT_MOC_LITERAL(6, 50, 11), // "signalInfAD"
QT_MOC_LITERAL(7, 62, 3), // "iad"
QT_MOC_LITERAL(8, 66, 11), // "signalInfAG"
QT_MOC_LITERAL(9, 78, 3), // "iag"
QT_MOC_LITERAL(10, 82, 21), // "connectionEstablished"
QT_MOC_LITERAL(11, 104, 7), // "getData"
QT_MOC_LITERAL(12, 112, 15), // "onDisconnection"
QT_MOC_LITERAL(13, 128, 7), // "onError"
QT_MOC_LITERAL(14, 136, 14) // "synchroniseBot"

    },
    "TCPClient\0reportConnection\0\0status\0"
    "signalBat\0valB\0signalInfAD\0iad\0"
    "signalInfAG\0iag\0connectionEstablished\0"
    "getData\0onDisconnection\0onError\0"
    "synchroniseBot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TCPClient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    1,   62,    2, 0x06 /* Public */,
       6,    1,   65,    2, 0x06 /* Public */,
       8,    1,   68,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   71,    2, 0x08 /* Private */,
      11,    0,   72,    2, 0x08 /* Private */,
      12,    0,   73,    2, 0x08 /* Private */,
      13,    0,   74,    2, 0x08 /* Private */,
      14,    0,   75,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TCPClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TCPClient *_t = static_cast<TCPClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->reportConnection((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->signalBat((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->signalInfAD((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->signalInfAG((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->connectionEstablished(); break;
        case 5: _t->getData(); break;
        case 6: _t->onDisconnection(); break;
        case 7: _t->onError(); break;
        case 8: _t->synchroniseBot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TCPClient::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TCPClient::reportConnection)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (TCPClient::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TCPClient::signalBat)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (TCPClient::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TCPClient::signalInfAD)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (TCPClient::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TCPClient::signalInfAG)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject TCPClient::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TCPClient.data,
      qt_meta_data_TCPClient,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TCPClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TCPClient::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TCPClient.stringdata0))
        return static_cast<void*>(const_cast< TCPClient*>(this));
    return QObject::qt_metacast(_clname);
}

int TCPClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void TCPClient::reportConnection(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TCPClient::signalBat(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TCPClient::signalInfAD(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TCPClient::signalInfAG(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
