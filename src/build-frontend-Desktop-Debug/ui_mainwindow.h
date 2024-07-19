/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>
#include "display_window.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_100;
    QLabel *label_101;
    QLabel *label_3;
    QSpinBox *lineEdit_translation_x;
    QSpinBox *lineEdit_translation_y;
    QSpinBox *lineEdit_translation_z;
    QLabel *label_8;
    QDial *xDial;
    QDial *yDial;
    QDial *zDial;
    QSpinBox *lineEdit_rotation_x;
    QSpinBox *lineEdit_rotation_y;
    QSpinBox *lineEdit_rotation_z;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_number_of_vertices;
    QLabel *label_number_of_edges;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_26;
    QLabel *label_30;
    QLineEdit *lineEdit_line_width;
    QPushButton *pushButton_apply_changes;
    QLabel *label_31;
    QLabel *label_32;
    QLineEdit *lineEdit_point_size;
    QComboBox *fileType;
    QPushButton *pushButton_save_image;
    QPushButton *pushButton_make_gif;
    Display_window *display_window;
    QDoubleSpinBox *lineEdit_scale_x;
    QTextBrowser *textBrowser_name_of_file;
    QTextBrowser *textBrowser_name_of_model;
    QPushButton *pushButton_open_obj_file;
    QLabel *label_33;
    QComboBox *qcombobox_typeProjection;
    QComboBox *qcombobox_displayVertices;
    QComboBox *qcombobox_edgesType;
    QSlider *backgroundColor_red;
    QSlider *backgroundColor_green;
    QSlider *backgroundColor_blue;
    QSlider *lineColor_blue;
    QSlider *lineColor_green;
    QSlider *lineColor_red;
    QLabel *label_27;
    QLabel *label_28;
    QSlider *vertColor_green;
    QSlider *vertColor_blue;
    QSlider *vertColor_red;
    QPushButton *pushButton_default_settings;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1487, 818);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_100 = new QLabel(centralwidget);
        label_100->setObjectName(QString::fromUtf8("label_100"));
        label_100->setGeometry(QRect(30, 10, 121, 31));
        label_101 = new QLabel(centralwidget);
        label_101->setObjectName(QString::fromUtf8("label_101"));
        label_101->setGeometry(QRect(30, 40, 141, 31));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(410, 150, 211, 21));
        lineEdit_translation_x = new QSpinBox(centralwidget);
        lineEdit_translation_x->setObjectName(QString::fromUtf8("lineEdit_translation_x"));
        lineEdit_translation_x->setGeometry(QRect(420, 180, 151, 25));
        lineEdit_translation_x->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"            padding-right: 5px;\n"
"        }"));
        lineEdit_translation_x->setWrapping(true);
        lineEdit_translation_x->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_translation_x->setMinimum(-360);
        lineEdit_translation_x->setMaximum(360);
        lineEdit_translation_y = new QSpinBox(centralwidget);
        lineEdit_translation_y->setObjectName(QString::fromUtf8("lineEdit_translation_y"));
        lineEdit_translation_y->setGeometry(QRect(420, 210, 151, 25));
        lineEdit_translation_y->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"            padding-right: 5px;\n"
"        }"));
        lineEdit_translation_y->setWrapping(true);
        lineEdit_translation_y->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_translation_y->setMinimum(-360);
        lineEdit_translation_y->setMaximum(360);
        lineEdit_translation_z = new QSpinBox(centralwidget);
        lineEdit_translation_z->setObjectName(QString::fromUtf8("lineEdit_translation_z"));
        lineEdit_translation_z->setGeometry(QRect(420, 240, 151, 25));
        lineEdit_translation_z->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"            padding-right: 5px;\n"
"        }"));
        lineEdit_translation_z->setWrapping(true);
        lineEdit_translation_z->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_translation_z->setMinimum(-360);
        lineEdit_translation_z->setMaximum(360);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(30, 140, 211, 21));
        xDial = new QDial(centralwidget);
        xDial->setObjectName(QString::fromUtf8("xDial"));
        xDial->setGeometry(QRect(30, 160, 80, 80));
        xDial->setMinimumSize(QSize(80, 80));
        xDial->setMaximumSize(QSize(80, 80));
        xDial->setMinimum(-360);
        xDial->setMaximum(360);
        xDial->setPageStep(1);
        xDial->setValue(0);
        xDial->setSliderPosition(0);
        xDial->setTracking(true);
        xDial->setOrientation(Qt::Horizontal);
        xDial->setWrapping(true);
        xDial->setNotchesVisible(false);
        yDial = new QDial(centralwidget);
        yDial->setObjectName(QString::fromUtf8("yDial"));
        yDial->setGeometry(QRect(150, 160, 80, 80));
        yDial->setMinimumSize(QSize(80, 80));
        yDial->setMaximumSize(QSize(80, 80));
        yDial->setMinimum(-360);
        yDial->setMaximum(360);
        yDial->setPageStep(1);
        yDial->setValue(0);
        yDial->setInvertedAppearance(false);
        yDial->setWrapping(true);
        zDial = new QDial(centralwidget);
        zDial->setObjectName(QString::fromUtf8("zDial"));
        zDial->setGeometry(QRect(270, 160, 80, 80));
        zDial->setMinimumSize(QSize(80, 80));
        zDial->setMaximumSize(QSize(80, 80));
        zDial->setMinimum(-360);
        zDial->setMaximum(360);
        zDial->setPageStep(1);
        zDial->setValue(0);
        zDial->setSliderPosition(0);
        zDial->setOrientation(Qt::Horizontal);
        zDial->setInvertedAppearance(false);
        zDial->setInvertedControls(false);
        zDial->setWrapping(true);
        lineEdit_rotation_x = new QSpinBox(centralwidget);
        lineEdit_rotation_x->setObjectName(QString::fromUtf8("lineEdit_rotation_x"));
        lineEdit_rotation_x->setGeometry(QRect(20, 240, 101, 25));
        lineEdit_rotation_x->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"            padding-right: 5px;\n"
"        }"));
        lineEdit_rotation_x->setWrapping(true);
        lineEdit_rotation_x->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_rotation_x->setMinimum(-360);
        lineEdit_rotation_x->setMaximum(360);
        lineEdit_rotation_y = new QSpinBox(centralwidget);
        lineEdit_rotation_y->setObjectName(QString::fromUtf8("lineEdit_rotation_y"));
        lineEdit_rotation_y->setGeometry(QRect(140, 240, 101, 25));
        lineEdit_rotation_y->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"            padding-right: 5px;\n"
"        }"));
        lineEdit_rotation_y->setWrapping(true);
        lineEdit_rotation_y->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_rotation_y->setMinimum(-360);
        lineEdit_rotation_y->setMaximum(360);
        lineEdit_rotation_z = new QSpinBox(centralwidget);
        lineEdit_rotation_z->setObjectName(QString::fromUtf8("lineEdit_rotation_z"));
        lineEdit_rotation_z->setGeometry(QRect(260, 240, 101, 25));
        lineEdit_rotation_z->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"            padding-right: 5px;\n"
"        }"));
        lineEdit_rotation_z->setWrapping(true);
        lineEdit_rotation_z->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_rotation_z->setMinimum(-360);
        lineEdit_rotation_z->setMaximum(360);
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(20, 280, 211, 21));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(30, 70, 141, 31));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(30, 100, 131, 31));
        label_number_of_vertices = new QLabel(centralwidget);
        label_number_of_vertices->setObjectName(QString::fromUtf8("label_number_of_vertices"));
        label_number_of_vertices->setGeometry(QRect(190, 80, 101, 17));
        label_number_of_edges = new QLabel(centralwidget);
        label_number_of_edges->setObjectName(QString::fromUtf8("label_number_of_edges"));
        label_number_of_edges->setGeometry(QRect(190, 110, 101, 17));
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(20, 350, 241, 17));
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(20, 400, 241, 17));
        label_26 = new QLabel(centralwidget);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(300, 280, 111, 21));
        label_30 = new QLabel(centralwidget);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(150, 540, 161, 21));
        lineEdit_line_width = new QLineEdit(centralwidget);
        lineEdit_line_width->setObjectName(QString::fromUtf8("lineEdit_line_width"));
        lineEdit_line_width->setGeometry(QRect(150, 580, 81, 25));
        pushButton_apply_changes = new QPushButton(centralwidget);
        pushButton_apply_changes->setObjectName(QString::fromUtf8("pushButton_apply_changes"));
        pushButton_apply_changes->setGeometry(QRect(460, 50, 141, 81));
        pushButton_apply_changes->setStyleSheet(QString::fromUtf8("QPushButton:pressed {\n"
"	background-color: rgb(16, 19, 33);\n"
"	color: white;\n"
"}\n"
""));
        label_31 = new QLabel(centralwidget);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(20, 470, 191, 21));
        label_32 = new QLabel(centralwidget);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(20, 540, 131, 21));
        lineEdit_point_size = new QLineEdit(centralwidget);
        lineEdit_point_size->setObjectName(QString::fromUtf8("lineEdit_point_size"));
        lineEdit_point_size->setGeometry(QRect(20, 580, 81, 25));
        fileType = new QComboBox(centralwidget);
        fileType->addItem(QString());
        fileType->addItem(QString());
        fileType->setObjectName(QString::fromUtf8("fileType"));
        fileType->setGeometry(QRect(500, 670, 108, 25));
        QFont font;
        font.setFamily(QString::fromUtf8("Optima"));
        font.setPointSize(14);
        fileType->setFont(font);
        fileType->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border-radius: 3px;\n"
"	border-color: rgb(63, 63, 63);\n"
"    }\n"
"        "));
        pushButton_save_image = new QPushButton(centralwidget);
        pushButton_save_image->setObjectName(QString::fromUtf8("pushButton_save_image"));
        pushButton_save_image->setGeometry(QRect(370, 720, 241, 31));
        pushButton_save_image->setStyleSheet(QString::fromUtf8("QPushButton:pressed {\n"
"	background-color: rgb(16, 19, 33);\n"
"	color: white;\n"
"}\n"
""));
        pushButton_make_gif = new QPushButton(centralwidget);
        pushButton_make_gif->setObjectName(QString::fromUtf8("pushButton_make_gif"));
        pushButton_make_gif->setGeometry(QRect(100, 720, 241, 31));
        pushButton_make_gif->setStyleSheet(QString::fromUtf8("QPushButton:pressed {\n"
"	background-color: rgb(16, 19, 33);\n"
"	color: white;\n"
"}\n"
""));
        display_window = new Display_window(centralwidget);
        display_window->setObjectName(QString::fromUtf8("display_window"));
        display_window->setGeometry(QRect(630, -1, 831, 771));
        lineEdit_scale_x = new QDoubleSpinBox(centralwidget);
        lineEdit_scale_x->setObjectName(QString::fromUtf8("lineEdit_scale_x"));
        lineEdit_scale_x->setGeometry(QRect(20, 310, 101, 25));
        lineEdit_scale_x->setMinimum(0.100000000000000);
        lineEdit_scale_x->setMaximum(100000.000000000000000);
        lineEdit_scale_x->setSingleStep(1.000000000000000);
        lineEdit_scale_x->setValue(10.000000000000000);
        textBrowser_name_of_file = new QTextBrowser(centralwidget);
        textBrowser_name_of_file->setObjectName(QString::fromUtf8("textBrowser_name_of_file"));
        textBrowser_name_of_file->setGeometry(QRect(190, 10, 251, 31));
        textBrowser_name_of_model = new QTextBrowser(centralwidget);
        textBrowser_name_of_model->setObjectName(QString::fromUtf8("textBrowser_name_of_model"));
        textBrowser_name_of_model->setGeometry(QRect(190, 40, 251, 31));
        pushButton_open_obj_file = new QPushButton(centralwidget);
        pushButton_open_obj_file->setObjectName(QString::fromUtf8("pushButton_open_obj_file"));
        pushButton_open_obj_file->setGeometry(QRect(460, 10, 141, 25));
        pushButton_open_obj_file->setStyleSheet(QString::fromUtf8("QPushButton:pressed {\n"
"	background-color: rgb(16, 19, 33);\n"
"	color: white;\n"
"}\n"
""));
        label_33 = new QLabel(centralwidget);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(370, 670, 131, 21));
        qcombobox_typeProjection = new QComboBox(centralwidget);
        qcombobox_typeProjection->addItem(QString());
        qcombobox_typeProjection->addItem(QString());
        qcombobox_typeProjection->setObjectName(QString::fromUtf8("qcombobox_typeProjection"));
        qcombobox_typeProjection->setGeometry(QRect(20, 370, 79, 22));
        qcombobox_displayVertices = new QComboBox(centralwidget);
        qcombobox_displayVertices->addItem(QString());
        qcombobox_displayVertices->addItem(QString());
        qcombobox_displayVertices->addItem(QString());
        qcombobox_displayVertices->setObjectName(QString::fromUtf8("qcombobox_displayVertices"));
        qcombobox_displayVertices->setGeometry(QRect(20, 500, 79, 22));
        qcombobox_edgesType = new QComboBox(centralwidget);
        qcombobox_edgesType->addItem(QString());
        qcombobox_edgesType->addItem(QString());
        qcombobox_edgesType->setObjectName(QString::fromUtf8("qcombobox_edgesType"));
        qcombobox_edgesType->setGeometry(QRect(20, 430, 79, 22));
        backgroundColor_red = new QSlider(centralwidget);
        backgroundColor_red->setObjectName(QString::fromUtf8("backgroundColor_red"));
        backgroundColor_red->setGeometry(QRect(310, 320, 16, 231));
        backgroundColor_red->setStyleSheet(QString::fromUtf8("background-color: #FFD3D3;"));
        backgroundColor_red->setMaximum(255);
        backgroundColor_red->setOrientation(Qt::Vertical);
        backgroundColor_green = new QSlider(centralwidget);
        backgroundColor_green->setObjectName(QString::fromUtf8("backgroundColor_green"));
        backgroundColor_green->setGeometry(QRect(330, 320, 16, 231));
        backgroundColor_green->setStyleSheet(QString::fromUtf8("background-color: #D3FFD3;"));
        backgroundColor_green->setMaximum(255);
        backgroundColor_green->setOrientation(Qt::Vertical);
        backgroundColor_blue = new QSlider(centralwidget);
        backgroundColor_blue->setObjectName(QString::fromUtf8("backgroundColor_blue"));
        backgroundColor_blue->setGeometry(QRect(350, 320, 16, 231));
        backgroundColor_blue->setStyleSheet(QString::fromUtf8("background-color: #D3D3FF;"));
        backgroundColor_blue->setMaximum(255);
        backgroundColor_blue->setOrientation(Qt::Vertical);
        lineColor_blue = new QSlider(centralwidget);
        lineColor_blue->setObjectName(QString::fromUtf8("lineColor_blue"));
        lineColor_blue->setGeometry(QRect(460, 320, 16, 231));
        lineColor_blue->setStyleSheet(QString::fromUtf8("background-color: #D3D3FF;"));
        lineColor_blue->setMaximum(255);
        lineColor_blue->setOrientation(Qt::Vertical);
        lineColor_green = new QSlider(centralwidget);
        lineColor_green->setObjectName(QString::fromUtf8("lineColor_green"));
        lineColor_green->setGeometry(QRect(440, 320, 16, 231));
        lineColor_green->setStyleSheet(QString::fromUtf8("background-color: #D3FFD3;"));
        lineColor_green->setMaximum(255);
        lineColor_green->setOrientation(Qt::Vertical);
        lineColor_red = new QSlider(centralwidget);
        lineColor_red->setObjectName(QString::fromUtf8("lineColor_red"));
        lineColor_red->setGeometry(QRect(420, 320, 16, 231));
        lineColor_red->setStyleSheet(QString::fromUtf8("background-color: #FFD3D3;"));
        lineColor_red->setMaximum(255);
        lineColor_red->setOrientation(Qt::Vertical);
        label_27 = new QLabel(centralwidget);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(430, 280, 111, 21));
        label_28 = new QLabel(centralwidget);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(520, 280, 111, 21));
        vertColor_green = new QSlider(centralwidget);
        vertColor_green->setObjectName(QString::fromUtf8("vertColor_green"));
        vertColor_green->setGeometry(QRect(540, 320, 16, 231));
        vertColor_green->setStyleSheet(QString::fromUtf8("background-color: #D3FFD3;"));
        vertColor_green->setMaximum(255);
        vertColor_green->setOrientation(Qt::Vertical);
        vertColor_blue = new QSlider(centralwidget);
        vertColor_blue->setObjectName(QString::fromUtf8("vertColor_blue"));
        vertColor_blue->setGeometry(QRect(560, 320, 16, 231));
        vertColor_blue->setStyleSheet(QString::fromUtf8("background-color: #D3D3FF;"));
        vertColor_blue->setMaximum(255);
        vertColor_blue->setOrientation(Qt::Vertical);
        vertColor_red = new QSlider(centralwidget);
        vertColor_red->setObjectName(QString::fromUtf8("vertColor_red"));
        vertColor_red->setGeometry(QRect(520, 320, 16, 231));
        vertColor_red->setStyleSheet(QString::fromUtf8("background-color: #FFD3D3;"));
        vertColor_red->setMaximum(255);
        vertColor_red->setOrientation(Qt::Vertical);
        pushButton_default_settings = new QPushButton(centralwidget);
        pushButton_default_settings->setObjectName(QString::fromUtf8("pushButton_default_settings"));
        pushButton_default_settings->setGeometry(QRect(310, 580, 271, 25));
        pushButton_default_settings->setStyleSheet(QString::fromUtf8("QPushButton:pressed {\n"
"	background-color: rgb(16, 19, 33);\n"
"	color: white;\n"
"}"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1487, 19));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_100->setText(QCoreApplication::translate("MainWindow", "Name of the file", nullptr));
        label_101->setText(QCoreApplication::translate("MainWindow", "Name of the model", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Translation of the the model", nullptr));
        lineEdit_translation_x->setSuffix(QCoreApplication::translate("MainWindow", " _x", nullptr));
        lineEdit_translation_y->setSuffix(QCoreApplication::translate("MainWindow", " _y", nullptr));
        lineEdit_translation_z->setSuffix(QCoreApplication::translate("MainWindow", " _z", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Rotation of the the model", nullptr));
        lineEdit_rotation_x->setSuffix(QCoreApplication::translate("MainWindow", "\302\260_x", nullptr));
        lineEdit_rotation_y->setSuffix(QCoreApplication::translate("MainWindow", "\302\260_y", nullptr));
        lineEdit_rotation_z->setSuffix(QCoreApplication::translate("MainWindow", "\302\260_z", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Scaling of the the model", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Number of vertices", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Number of edges", nullptr));
        label_number_of_vertices->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_number_of_edges->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Customizing the type of projection", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Customizing edges", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "Background", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "Edges thickness", nullptr));
        lineEdit_line_width->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_apply_changes->setText(QCoreApplication::translate("MainWindow", "Apply changes", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "Display method of vertices", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "Vertices size", nullptr));
        lineEdit_point_size->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        fileType->setItemText(0, QCoreApplication::translate("MainWindow", ".jpeg", nullptr));
        fileType->setItemText(1, QCoreApplication::translate("MainWindow", ".bmp", nullptr));

        fileType->setProperty("text", QVariant(QCoreApplication::translate("MainWindow", ".jpeg", nullptr)));
        pushButton_save_image->setText(QCoreApplication::translate("MainWindow", "Save image", nullptr));
        pushButton_make_gif->setText(QCoreApplication::translate("MainWindow", "Record screencast", nullptr));
        textBrowser_name_of_file->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt; font-style:italic; color:#868686;\">Name of the file</span></p></body></html>", nullptr));
        textBrowser_name_of_model->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt; font-style:italic; color:#868686;\">Name of the model</span></p></body></html>", nullptr));
        pushButton_open_obj_file->setText(QCoreApplication::translate("MainWindow", "Open the .obj file", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "Select type image:", nullptr));
        qcombobox_typeProjection->setItemText(0, QCoreApplication::translate("MainWindow", "parallel", nullptr));
        qcombobox_typeProjection->setItemText(1, QCoreApplication::translate("MainWindow", "central", nullptr));

        qcombobox_displayVertices->setItemText(0, QCoreApplication::translate("MainWindow", "none", nullptr));
        qcombobox_displayVertices->setItemText(1, QCoreApplication::translate("MainWindow", "circle", nullptr));
        qcombobox_displayVertices->setItemText(2, QCoreApplication::translate("MainWindow", "square", nullptr));

        qcombobox_edgesType->setItemText(0, QCoreApplication::translate("MainWindow", "solid", nullptr));
        qcombobox_edgesType->setItemText(1, QCoreApplication::translate("MainWindow", "dashed", nullptr));

        label_27->setText(QCoreApplication::translate("MainWindow", "Edges", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "Vertices", nullptr));
        pushButton_default_settings->setText(QCoreApplication::translate("MainWindow", "Set to default settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
