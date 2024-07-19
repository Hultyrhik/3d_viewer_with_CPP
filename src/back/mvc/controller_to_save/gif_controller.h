#ifndef GIFCONTROLLER_H
#define GIFCONTROLLER_H

#include <QImage>
#include <QString>

#include "../model_to_save/director.h"
#include "../model_to_save/gif_builder.h"

namespace s21 {
class GIFController {
 public:
  GIFController(const QString& modelName, uint8_t* image, int width,
                int height);
  void saveGIF();

 private:
  QString modelName;
  uint8_t* image;
  int width;
  int height;
};
}  // namespace s21

#endif  // GIFCONTROLLER_H
