QT       += core gui
QT       += opengl


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../back/s21_3dparser.c \
    display_window.cpp \
    main.cpp \
    save_settings.cpp \
    mainwindow.cpp \
    ../gif/gif.cpp \

HEADERS += \
    ../back/s21_3dparser.h \
    display_window.h \
    mainwindow.h \ 
    ../gif/gif.hpp \

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
