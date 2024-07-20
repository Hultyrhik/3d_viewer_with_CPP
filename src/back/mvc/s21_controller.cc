#include "s21_controller.h"

#include <iostream>

#include "s21_model.h"

namespace s21 {
int Controller::init_model() {
  this->model_->s21_clearModelShape();

  this->model_->s21_zeroingShape();

  return this->model_->s21_initShape();
}
}  // namespace s21