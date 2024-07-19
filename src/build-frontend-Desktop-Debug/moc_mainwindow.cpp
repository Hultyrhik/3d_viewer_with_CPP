/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../frontend/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[19];
    char stringdata0[522];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 35), // "on_pushButton_apply_changes_c..."
QT_MOC_LITERAL(2, 47, 0), // ""
QT_MOC_LITERAL(3, 48, 35), // "on_pushButton_open_obj_file_c..."
QT_MOC_LITERAL(4, 84, 30), // "on_pushButton_make_gif_clicked"
QT_MOC_LITERAL(5, 115, 32), // "on_pushButton_save_image_clicked"
QT_MOC_LITERAL(6, 148, 38), // "on_pushButton_default_setting..."
QT_MOC_LITERAL(7, 187, 35), // "on_lineEdit_rotation_x_valueC..."
QT_MOC_LITERAL(8, 223, 4), // "arg1"
QT_MOC_LITERAL(9, 228, 20), // "on_xDial_sliderMoved"
QT_MOC_LITERAL(10, 249, 8), // "position"
QT_MOC_LITERAL(11, 258, 20), // "on_yDial_sliderMoved"
QT_MOC_LITERAL(12, 279, 20), // "on_zDial_sliderMoved"
QT_MOC_LITERAL(13, 300, 35), // "on_lineEdit_rotation_y_valueC..."
QT_MOC_LITERAL(14, 336, 35), // "on_lineEdit_rotation_z_valueC..."
QT_MOC_LITERAL(15, 372, 38), // "on_lineEdit_translation_x_val..."
QT_MOC_LITERAL(16, 411, 38), // "on_lineEdit_translation_y_val..."
QT_MOC_LITERAL(17, 450, 38), // "on_lineEdit_translation_z_val..."
QT_MOC_LITERAL(18, 489, 32) // "on_lineEdit_scale_x_valueChanged"

    },
    "MainWindow\0on_pushButton_apply_changes_clicked\0"
    "\0on_pushButton_open_obj_file_clicked\0"
    "on_pushButton_make_gif_clicked\0"
    "on_pushButton_save_image_clicked\0"
    "on_pushButton_default_settings_clicked\0"
    "on_lineEdit_rotation_x_valueChanged\0"
    "arg1\0on_xDial_sliderMoved\0position\0"
    "on_yDial_sliderMoved\0on_zDial_sliderMoved\0"
    "on_lineEdit_rotation_y_valueChanged\0"
    "on_lineEdit_rotation_z_valueChanged\0"
    "on_lineEdit_translation_x_valueChanged\0"
    "on_lineEdit_translation_y_valueChanged\0"
    "on_lineEdit_translation_z_valueChanged\0"
    "on_lineEdit_scale_x_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    0,   91,    2, 0x08 /* Private */,
       5,    0,   92,    2, 0x08 /* Private */,
       6,    0,   93,    2, 0x08 /* Private */,
       7,    1,   94,    2, 0x08 /* Private */,
       9,    1,   97,    2, 0x08 /* Private */,
      11,    1,  100,    2, 0x08 /* Private */,
      12,    1,  103,    2, 0x08 /* Private */,
      13,    1,  106,    2, 0x08 /* Private */,
      14,    1,  109,    2, 0x08 /* Private */,
      15,    1,  112,    2, 0x08 /* Private */,
      16,    1,  115,    2, 0x08 /* Private */,
      17,    1,  118,    2, 0x08 /* Private */,
      18,    1,  121,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Double,    8,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_pushButton_apply_changes_clicked(); break;
        case 1: _t->on_pushButton_open_obj_file_clicked(); break;
        case 2: _t->on_pushButton_make_gif_clicked(); break;
        case 3: _t->on_pushButton_save_image_clicked(); break;
        case 4: _t->on_pushButton_default_settings_clicked(); break;
        case 5: _t->on_lineEdit_rotation_x_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_xDial_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_yDial_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_zDial_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_lineEdit_rotation_y_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_lineEdit_rotation_z_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_lineEdit_translation_x_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_lineEdit_translation_y_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->on_lineEdit_translation_z_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->on_lineEdit_scale_x_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
