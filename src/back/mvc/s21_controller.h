#ifndef S21_CONTROLLER_H
#define S21_CONTROLLER_H

#include "s21_model.h"

namespace s21 {

class Controller {
 private:
  Model* model_;

 public:
  Controller(Model* other) : model_{other} {}

  int init_model();
};

}  // namespace s21

#endif