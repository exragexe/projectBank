/****************************************************************************
** Meta object code from reading C++ file 'curr.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../project1/curr.h"
#include <QtGui/qtextcursor.h>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'curr.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASScurrENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASScurrENDCLASS = QtMocHelpers::stringData(
    "curr",
    "on_exi_clicked",
    "",
    "on_pushButton_4_clicked",
    "on_sel_clicked",
    "on_buy_clicked",
    "updateValuts"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASScurrENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[5];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[24];
    char stringdata4[15];
    char stringdata5[15];
    char stringdata6[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASScurrENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASScurrENDCLASS_t qt_meta_stringdata_CLASScurrENDCLASS = {
    {
        QT_MOC_LITERAL(0, 4),  // "curr"
        QT_MOC_LITERAL(5, 14),  // "on_exi_clicked"
        QT_MOC_LITERAL(20, 0),  // ""
        QT_MOC_LITERAL(21, 23),  // "on_pushButton_4_clicked"
        QT_MOC_LITERAL(45, 14),  // "on_sel_clicked"
        QT_MOC_LITERAL(60, 14),  // "on_buy_clicked"
        QT_MOC_LITERAL(75, 12)   // "updateValuts"
    },
    "curr",
    "on_exi_clicked",
    "",
    "on_pushButton_4_clicked",
    "on_sel_clicked",
    "on_buy_clicked",
    "updateValuts"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASScurrENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x08,    1 /* Private */,
       3,    0,   45,    2, 0x08,    2 /* Private */,
       4,    0,   46,    2, 0x08,    3 /* Private */,
       5,    0,   47,    2, 0x08,    4 /* Private */,
       6,    0,   48,    2, 0x08,    5 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject curr::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASScurrENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASScurrENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASScurrENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<curr, std::true_type>,
        // method 'on_exi_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_4_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_sel_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_buy_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateValuts'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void curr::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<curr *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_exi_clicked(); break;
        case 1: _t->on_pushButton_4_clicked(); break;
        case 2: _t->on_sel_clicked(); break;
        case 3: _t->on_buy_clicked(); break;
        case 4: _t->updateValuts(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *curr::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *curr::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASScurrENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int curr::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
