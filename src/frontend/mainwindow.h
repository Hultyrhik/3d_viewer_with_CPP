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

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

  Ui::MainWindow* ui;

 private slots:
  /**
   * @brief Slot to apply the changes to the model.
   */
  void on_pushButton_apply_changes_clicked();
  /**
   * @brief Slot to open the .obj file.
   */
  void on_pushButton_open_obj_file_clicked();
  /**
   * @brief Slot to make a GIF.
   */
  void on_pushButton_make_gif_clicked();
  /**
   * @brief Slot to save the image.
   */
  void on_pushButton_save_image_clicked();
  /**
   * @brief Slot to set the default settings.
   */
  void on_pushButton_default_settings_clicked();
  /**
   * @brief Slot to change the rotation X.
   * @param arg1 The new value.
   */
  void on_lineEdit_rotation_x_valueChanged(int arg1);
  /**
   * @brief Slot to change the rotation X (for the slider).
   * @param position The new position.
   */
  void on_xDial_sliderMoved(int position);
  /**
   * @brief Slot to change the rotation Y.
   * @param arg1 The new value.
   */
  void on_lineEdit_rotation_y_valueChanged(int arg1);
  /**
   * @brief Slot to change the rotation Y (for the slider).
   * @param position The new position.
   */
  void on_yDial_sliderMoved(int position);
  /**
   * @brief Slot to change the rotation Z.
   * @param arg1 The new value.
   */
  void on_lineEdit_rotation_z_valueChanged(int arg1);
  /**
   * @brief Slot to change the rotation Z (for the slider).
   * @param position The new position.
   */
  void on_zDial_sliderMoved(int position);
  /**
   * @brief Slot to change the translation X.
   * @param arg1 The new value.
   */
  void on_lineEdit_translation_x_valueChanged(int arg1);
  /**
   * @brief Slot to change the translation Y.
   * @param arg1 The new value.
   */
  void on_lineEdit_translation_y_valueChanged(int arg1);
  /**
   * @brief Slot to change the translation Z.
   * @param arg1 The new value.
   */
  void on_lineEdit_translation_z_valueChanged(int arg1);
  /**
   * @brief Slot to change the scale X.
   * @param arg1 The new value.
   */
  void on_lineEdit_scale_x_valueChanged(double arg1);

 private:
  /**
   * @brief Function to connect the buttons.
   */
  void connectButtons();
  /**
   * @brief Function to display an error message.
   */
  void MessageError();
  /**
   * @brief Function to write the settings to the file.
   */
  void writeSettings();
  /**
   * @brief Function to read the settings from the file.
   */
  void readSettings();
  /**
   * @brief Function to read the .obj file.
   */
  void read_obj_file();
  /**
   * @brief Function to write the parameters to the UI.
   */
  void write_to_ui();
  /**
   * @brief Function to set the default settings.
   */
  void set_parameters_to_default();
  /**
   * @brief Function to set the model transformations to zero.
   */
  void set_model_transformations_to_zero();
  /**
   * @brief Function to override the default closeEvent.
   * @param event The close event.
   */
  void closeEvent(QCloseEvent* event);

 protected:
  /**
   * @brief Function to override the default keyPressEvent.
   * @param event The key press event.
   */
  void keyPressEvent(QKeyEvent* event) override;
};

/**
 * @brief Function to initialize the background color.
 * @param array The array to initialize.
 */
void init_backgroud_color(double* array);
/**
 * @brief Function to initialize the point color.
 * @param array The array to initialize.
 */
void init_point_color(double* array);
/**
 * @brief Function to initialize the line color.
 * @param array The array to initialize.
 */
void init_line_color(double* array);
/**
 * @brief Function to normalize the color.
 * @param array The array to normalize.
 */
void color_normalization(double* array);

#endif  // MAINWINDOW_H
