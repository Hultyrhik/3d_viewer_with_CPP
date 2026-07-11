#ifndef CONTRACT_PROJECTION_H
#define CONTRACT_PROJECTION_H

#include "../../../frontend/display_window.h"
#include "../model_projection/projection_strategy.h"

namespace s21 {

/**
 * @brief The ControllerProjection class
 *
 * This class is a controller for changing the projection strategy. It can
 * return the appropriate projection strategy based on the given
 * Projection_type and apply the projection.
 */
class ControllerProjection {
 private:
  /**
   * @brief Returns the appropriate projection strategy based on the given type
   * @param type The type of projection strategy to return
   * @return The appropriate projection strategy
   */
  ProjectionStrategy* getProjectionStrategy(Projection_type type) {
    if (type == Projection_type::CENTRAL) {
      return new CentralProjection();
    } else {
      return new ParallelProjection();
    }
  }

 public:
  /**
   * @brief Applies the projection strategy associated with the given type
   * @param type The type of projection strategy to apply
   */
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
