#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCloseEvent>
#include <QFileDialog>
#include <QMainWindow>
#include <QSpinBox>

#include "../back/mvc/controller_to_save/gif_controller.h"
#include "../back/mvc/controller_to_save/screen_controller.h"

// Include necessary headers
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

// Declare the MainWindow class
class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  // Constructor and destructor
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

  Ui::MainWindow* ui;  // Pointer to the MainWindow UI

 private slots:
  // Slots for button clicks and value changes
  void on_pushButton_apply_changes_clicked();
  void on_pushButton_open_obj_file_clicked();
  void on_pushButton_make_gif_clicked();
  void on_pushButton_save_image_clicked();
  void on_pushButton_default_settings_clicked();
  void on_lineEdit_rotation_x_valueChanged(int arg1);
  void on_xDial_sliderMoved(int position);
  void on_yDial_sliderMoved(int position);
  void on_zDial_sliderMoved(int position);
  void on_lineEdit_rotation_y_valueChanged(int arg1);
  void on_lineEdit_rotation_z_valueChanged(int arg1);
  void on_lineEdit_translation_x_valueChanged(int arg1);
  void on_lineEdit_translation_y_valueChanged(int arg1);
  void on_lineEdit_translation_z_valueChanged(int arg1);
  void on_lineEdit_scale_x_valueChanged(double arg1);

 private:
  // Private member functions
  void connectButtons();
  void writeSettings();
  void readSettings();
  void read_obj_file();
  void write_to_ui();
  void set_parameters_to_default();
  void set_model_transformations_to_zero();
  void closeEvent(QCloseEvent* event);

 protected:
  // Protected member function
  void keyPressEvent(QKeyEvent* event) override;
};

// Function declarations
void init_backgroud_color(double* array);
void init_point_color(double* array);
void init_line_color(double* array);
void color_normalization(double* array);

#endif  // MAINWINDOW_H
