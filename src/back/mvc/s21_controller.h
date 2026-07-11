#ifndef S21_CONTROLLER_H
#define S21_CONTROLLER_H

#include "s21_model.h"

namespace s21 {

/**
 * @brief The Controller class.
 *
 * This class is responsible for controlling the Model and View objects
 * in the MVC design pattern. It provides a method for initializing the
 * Model object and returning an error code if the initialization fails.
 */
class Controller {
 private:
  Model* model_;

 public:
  Controller(Model* other) : model_{other} {}

  /**
   * @brief Initialize model by zeroing its shape, clearing its memory and
   * filling it with data from the file.
   *
   * This method initializes the Model object by zeroing its shape,
   * clearing its memory and filling it with data from the file. It
   * returns an integer code indicating the status of the initialization.
   * If the initialization is successful, the method returns 0. Otherwise,
   * it returns 1.
   *
   * @return 0 if successful, 1 if failed.
   */
  int init_model();
};

}  // namespace s21

#endif