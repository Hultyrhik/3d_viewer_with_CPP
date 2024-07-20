#ifndef S21_VIEW_H
#define S21_VIEW_H

#include "s21_controller.h"

namespace s21 {
/**
 * @brief The View class.
 *
 * This class is a part of the MVC (Model-View-Controller) design pattern.
 * It provides a method for initializing the Controller object and returns an
 * error code indicating the status of the initialization.
 */
class View {
 private:
  Controller* controller_;

 public:
  /**
   * @brief Construct a new View object.
   *
   * @param other The Controller object to be initialized.
   */
  View(Controller* other) : controller_{other} {}
  /**
   * @brief Initialize the Controller object.
   *
   * This method initializes the Controller object and returns an error code
   * indicating the status of the initialization.
   *
   * @return 0 if successful, 1 if failed.
   */
  int init_controller();
};
}  // namespace s21

#endif