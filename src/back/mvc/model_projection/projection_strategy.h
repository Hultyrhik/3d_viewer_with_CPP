#ifndef PROJECTION_STRATEGY_H_
#define PROJECTION_STRATEGY_H_

#include <QOpenGLWidget>
#include <cmath>

#include "../s21_3dparser.h"
namespace s21 {
/**
 * @brief The ProjectionStrategy class is an abstract base class for
 * projection strategies. It provides a virtual function to apply a
 * projection strategy.
 */
class ProjectionStrategy {
 public:
  /**
   * @brief Apply the projection strategy.
   */
  virtual void applyProjection() = 0;

  virtual ~ProjectionStrategy() = default;
};

/**
 * @brief The ParallelProjection class is a projection strategy that
 * applies a parallel projection.
 */
class ParallelProjection : public ProjectionStrategy {
 public:
  /**
   * @brief Apply the parallel projection.
   *
   * This function sets the projection matrix to an orthographic
   * projection. It sets the left, right, bottom, top, near, and far
   * clipping planes to the specified values.
   */
  void applyProjection() override { glOrtho(-1, 1, -1, 1, -10, 10); }
};

/**
 * @brief The CentralProjection class is a projection strategy that
 * applies a central projection. This is a perspective projection that
 * simulates how the human eye sees the world.
 */
class CentralProjection : public ProjectionStrategy {
 public:
  /**
   * @brief Apply the central projection.
   *
   * This function sets the projection matrix to a perspective
   * projection. The field of view is set to 60 degrees, and the
   * near and far clipping planes are set to 1 and 100, respectively.
   */
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