#include "display_window.h"

#include <cmath>

#include "../back/mvc/controller_projection/controller_projection.h"
#include "../back/mvc/s21_3dparser.h"
#include "../back/mvc/s21_controller.h"
#include "../back/mvc/s21_model.h"
#include "../back/mvc/s21_view.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

Display_window::Display_window(QWidget* parent) : QOpenGLWidget(parent) {
  shape = new Shape;
  this->model = new s21::Model(shape);
  this->controller = new s21::Controller(this->model);
  this->view = new s21::View(this->controller);
  is_ready_to_draw = false;
  glwidth = 771, glheight = 771;
}

void Display_window::initializeGL() {}

void Display_window::paintGL() { renderOpenGLScene(); }

void Display_window::renderOpenGLScene() {
  if (shape->vertexes != nullptr && shape->lines != nullptr &&
      is_ready_to_draw == true) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_DEPTH_TEST);

    s21::figure_rotation(shape, my_data.rotation[0], my_data.rotation[1],
                         my_data.rotation[2]);

    s21::s21_setScale(shape, (my_data.scale[0] / 10));

    s21::s21_shifting(shape, (my_data.translation[0] / 10), AXIS_X);
    s21::s21_shifting(shape, (my_data.translation[1] / 10), AXIS_Y);
    s21::s21_shifting(shape, (my_data.translation[2] / 10), AXIS_Z);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    s21::ControllerProjection controller;
    controller.setProjectionStrategy(my_data.projection_type);

    glClearColor(my_data.background_color[0], my_data.background_color[1],
                 my_data.background_color[2], 1.0f);

    glClear(GL_COLOR_BUFFER_BIT);

    glVertexPointer(3, GL_DOUBLE, 0, shape->vertexes);
    glPointSize(my_data.point_size);
    glLineWidth(my_data.line_width);

    if (my_data.line_type == DASHED) {
      glLineStipple(1, 0x00FF);
      glEnable(GL_LINE_STIPPLE);
    }

    glEnableClientState(GL_VERTEX_ARRAY);
    glColor3f(my_data.point_color[0], my_data.point_color[1],
              my_data.point_color[2]);

    if (my_data.point_type != NONE) {
      if (my_data.point_type == SQUARE) {
        glDisable(GL_POINT_SMOOTH);
        glDisable(GL_BLEND);
        glDisable(GL_ALPHA_TEST);
      } else {
        glEnable(GL_POINT_SMOOTH);
      }
      glDrawArrays(GL_POINTS, 0, shape->countV);
    }

    glColor3f(my_data.line_color[0], my_data.line_color[1],
              my_data.line_color[2]);

    if (my_data.line_type == SOLID) {
      glDisable(GL_LINE_STIPPLE);
      glEnable(GL_LINE_SMOOTH);
    } else {
      glDisable(GL_LINE_SMOOTH);
      glEnable(GL_LINE_STIPPLE);
      glLineStipple(2, 0x1111);
    }
    glDrawElements(GL_LINES, shape->countLines, GL_UNSIGNED_INT, shape->lines);

    glDisableClientState(GL_VERTEX_ARRAY);

    glReadPixels(0, 0, glwidth, glheight, GL_RGBA, GL_UNSIGNED_BYTE, image);
  }
}

void Display_window::resizeGL(int w, int h) { glViewport(0, 0, w, h); }

Display_window::~Display_window() {
  s21::s21_clearShape(shape);

  if (shape) {
    delete shape;
  }
  if (view) {
    delete view;
  }

  if (controller) {
    delete controller;
  }
  if (model) {
    delete model;
  }
}
