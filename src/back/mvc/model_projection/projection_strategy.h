#ifndef PROJECTION_STRATEGY_H_
#define PROJECTION_STRATEGY_H_

#include <QOpenGLWidget>
#include <cmath>

#include "../s21_3dparser.h"
namespace s21 {
class ProjectionStrategy {
 public:
  virtual void applyProjection() = 0;
  virtual ~ProjectionStrategy() = default;
};

class ParallelProjection : public ProjectionStrategy {
 public:
  void applyProjection() override { glOrtho(-1, 1, -1, 1, -10, 10); }
};

class CentralProjection : public ProjectionStrategy {
 public:
  void applyProjection() override {
    float fov = 60.0 * M_PI / 180;
    float heapHeight = 1 / (2 * std::tan(fov / 2));
    glFrustum(-1, 1, -1, 1, heapHeight, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslated(0, 0, -heapHeight * 3);
  }
};
}  // namespace s21

#endif  // PROJECTION_STRATEGY_H_