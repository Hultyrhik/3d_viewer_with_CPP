#ifndef SCREEN_BUILDER_H_
#define SCREEN_BUILDER_H_

#include "path_builder.h"

namespace s21 {
class Director {
 public:
  void setBuilder(FilePathBuilder* builder) { this->builder = builder; }
  QString construct() {
    builder->setSaveDirectory();
    builder->setFileName();
    return builder->getFilePath();
  }

 private:
  FilePathBuilder* builder;
};

}  // namespace s21

#endif  // SCREEN_BUILDER_H_