#ifndef S21_MODEL_H
#define S21_MODEL_H

#include <string>

#include "s21_3dparser.h"

namespace s21 {

class Model {
private:
    Shape* shape_;
    std::string path_of_file_;


public:
    Model(Shape* ptr, std::string path) : shape_{ptr}, path_of_file_{path}  {}
};


} // namespace s21


#endif