#include "display_window.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

Display_window::Display_window(QWidget* parent) : QOpenGLWidget(parent) {
  shape = static_cast<Shape*>(calloc(1, sizeof(Shape)));
  s21_zeroingShape(shape);
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

    figure_rotation(shape, my_data.rotation[0], my_data.rotation[1],
                    my_data.rotation[2]);

    s21_setScale(shape, (my_data.scale[0] / 10));

    s21_shifting(shape, (my_data.translation[0] / 10), AXIS_X);
    s21_shifting(shape, (my_data.translation[1] / 10), AXIS_Y);
    s21_shifting(shape, (my_data.translation[2] / 10), AXIS_Z);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (my_data.projection_type == CENTRAL) {
      //  winWidth и winHeight мы задавали также через минимальные и
      //  максимальные значения
      float winHeight = 1;
      float winWidth = 1;
      float fov = 60.0 * M_PI / 180;  // 60 угол в градусах
      float heapHeight = winHeight / (2 * tan(fov / 2));
      glFrustum(-winWidth, winWidth, -winHeight, winHeight, heapHeight, 100);
      // far можно задать любым, лишь бы все умещалось.
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
      glTranslated(0, 0, -heapHeight * 3);
    }
    if (my_data.projection_type == PARALLEL) {
      glOrtho(-1, 1, -1, 1, -10, 10);
    }

    glClearColor(my_data.background_color[0], my_data.background_color[1],
                 my_data.background_color[2], 1.0f);  // background color

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

void Display_window::saveGIF() {
  QString saveDirectory = "../../../misc/gif/";
  QString fileType = ".gif";

  QDir dir(saveDirectory);
  if (!dir.exists()) {
    dir.mkpath(".");
  }
  QString fileName = saveDirectory + "/";
  fileName.append(my_data.name_of_model.c_str());
  fileName.append(fileType);
  int delay = 100;
  GifWriter g;
  GifBegin(&g, fileName.toStdString().c_str(), 640, 480, delay);

  for (int timer = 0; timer <= 5000; timer += delay) {
    QImage tempImage(image, glwidth, glheight, QImage::Format_ARGB32);
    QRect sourceRect((glwidth - 640) / 2, (glheight - 480) / 2, 640, 480);
    tempImage = tempImage.copy(sourceRect);
    GifWriteFrame(&g, tempImage.bits(), 640, 480, 1);
    std::this_thread::sleep_for(std::chrono::milliseconds(delay));
  }

  qDebug() << "Gif is ready";
  GifEnd(&g);
}

Display_window::~Display_window() {
  if (shape) {
    s21_clearShape(shape);
    free(shape);
  }
}
