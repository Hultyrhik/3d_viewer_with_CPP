#ifndef CONTRACT_PROJECTION_H
#define CONTRACT_PROJECTION_H

#include "../../../frontend/display_window.h"
#include "../model_projection/projection_strategy.h"

namespace s21 {

class ControllerProjection {
 private:
  ProjectionStrategy* getProjectionStrategy(Projection_type type) {
    if (type == Projection_type::CENTRAL) {
      return new CentralProjection();
    } else {
      return new ParallelProjection();
    }
  }

 public:
  void setProjectionStrategy(Projection_type type) {
    ProjectionStrategy* projectionStrategy = getProjectionStrategy(type);
    if (projectionStrategy) {
      projectionStrategy->applyProjection();
      delete projectionStrategy;
    }
  }
};

}  // namespace s21
#endif  // CONTRACT_PROJECTION_H
