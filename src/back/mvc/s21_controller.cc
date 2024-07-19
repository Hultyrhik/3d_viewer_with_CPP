#include "s21_controller.h"

#include <iostream>

#include "s21_model.h"

namespace s21 {
int Controller::init_model() {
  this->model_->s21_clearModelShape();
  std::cout << "After clearModelShape" << std::endl;
  this->model_->s21_zeroingShape();
  std::cout << "After zeroingShape" << std::endl;
  return this->model_->s21_initShape();
}
}  // namespace s21