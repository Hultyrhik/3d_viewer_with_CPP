#ifndef DISPLAY_WINDOW_H
#define DISPLAY_WINDOW_H

#include <QDebug>
#include <QDesktopServices>
#include <QDir>
#include <QElapsedTimer>
#include <QFile>
#include <QImage>
#include <QMessageBox>
#include <QObject>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QPainter>
#include <QPixmap>
#include <QRect>
#include <QSettings>
#include <QString>
#include <QTime>
#include <chrono>
#include <filesystem>
#include <string>
#include <thread>

#include "../back/mvc/s21_3dparser.h"
#include "../back/mvc/s21_view.h"
#include "./../gif/gif.hpp"
#include "mainwindow.h"

using namespace Qt;

/**
 * @brief Enum to represent the type of point.
 */
typedef enum {
  NONE,   /**< No point */
  CIRCLE, /**< Circle point */
  SQUARE  /**< Square point */
} Point_type;

/**
 * @brief Enum to represent the type of line.
 */
typedef enum {
  SOLID, /**< Solid line */
  DASHED /**< Dashed line */
} Line_type;

/**
 * @brief Enum to represent the type of projection.
 */
typedef enum {
  CENTRAL, /**< Central projection */
  PARALLEL /**< Parallel projection */
} Projection_type;

/**
 * @brief Struct to store the settings.
 */
typedef struct Settings_storage_ {
  std::string name_of_file;
  std::string name_of_model;
  std::string path_to_file;
  int number_of_vertices, number_of_edges, point_size, line_width;
  double background_color[3], line_color[3], point_color[3], rotation[3],
      scale[3], translation[3];
  double rotation_display[3];
  Point_type point_type;
  Line_type line_type;
  Projection_type projection_type;
} Settings_storage;

/**
 * @brief Class representing the display window.
 */
class Display_window : public QOpenGLWidget {
  Q_OBJECT

 public:
  /**
   * @brief Constructor for the Display_window class.
   * @param parent The parent widget.
   */
  explicit Display_window(QWidget* parent = nullptr);

  s21::Model* model;
  s21::Controller* controller;
  s21::View* view;
  Shape* shape;             /**< The shape object. */
  Shape* init_shape;        /**< The initial shape object. */
  Settings_storage my_data; /**< The settings storage object. */
  bool is_ready_to_draw;    /**< Flag indicating if it is the first launch. */

 public slots:
  /**
   * @brief Slot for saving the GIF.
   */
  void saveGIF();

 private slots:

 protected:
  /**
   * @brief Function to initialize OpenGL.
   */
  void initializeGL() override;

  /**
   * @brief Function to paint the OpenGL scene.
   */
  void paintGL() override;

  /**
   * @brief Function to render the OpenGL scene.
   */
  void renderOpenGLScene();

  /**
   * @brief Function to resize the OpenGL viewport.
   * @param w The width of the viewport.
   * @param h The height of the viewport.
   */
  void resizeGL(int w, int h) override;

 private:
  uint8_t image[771 * 771 * 4]; /**< The image buffer. */
  int glwidth, glheight; /**< The width and height of the OpenGL viewport. */

  /**
   * @brief Destructor for the Display_window class.
   */
  ~Display_window();
};

#endif  // DISPLAY_WINDOW_H
