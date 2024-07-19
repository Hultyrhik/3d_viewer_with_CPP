QT       += core gui
QT       += opengl


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../back/mvc/s21_model.cc \
    ../back/mvc/s21_controller.cc \
    ../back/mvc/s21_view.cc \
    display_window.cpp \
    main.cpp \
    save_settings.cpp \
    mainwindow.cpp \
    ../gif/gif.cpp \
    ../back/mvc/controller_to_save/gif_controller.cc \
    ../back/mvc/controller_to_save/screen_controller.cc \

HEADERS += \
    ../back/mvc/s21_3dparser.h \
    ../back/mvc/s21_model.h \
    ../back/mvc/s21_controller.h \
    ../back/mvc/s21_view.h \
    display_window.h \
    mainwindow.h \ 
    ../gif/gif.hpp \
    ../back/mvc/controller_to_save/gif_controller.h \
    ../back/mvc/controller_to_save/screen_controller.h \
    ../back/mvc/model_to_save/director.h \
    ../back/mvc/model_to_save/path_builder.h \
    ../back/mvc/model_to_save/gif_builder.h \
    ../back/mvc/model_to_save/screen_builder.h \

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
