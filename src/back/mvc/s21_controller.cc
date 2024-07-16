#include "s21_controller.h"
#include "s21_model.h"


namespace s21 {
    void Controller::init_model(){
        this->model_->s21_clearModelShape();
        this->model_->s21_zeroingShape();
        this->model_->s21_initShape();
    }
}  // namespace s21