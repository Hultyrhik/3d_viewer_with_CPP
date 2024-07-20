#ifndef SCREEN_BUILDER_H_
#define SCREEN_BUILDER_H_

#include "path_builder.h"

namespace s21 {
/**
 * @brief Class for creating the path for saving a file.
 */
class Director {
 public:
  /**
   * @brief Set the builder for creating the path.
   *
   * @param builder The builder for creating the path.
   */
  void setBuilder(FilePathBuilder* builder) { this->builder = builder; }
  /**
   * @brief Create the path for saving a file.
   *
   * @return The path for saving a file.
   */
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