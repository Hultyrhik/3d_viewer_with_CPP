#include "s21_view.h"

namespace s21 {
int View::init_controller() { return this->controller_->init_model(); }
}  // namespace s21