#ifndef SCREENCONTROLLER_H
#define SCREENCONTROLLER_H

#include <QImage>
#include <QString>

#include "../model_to_save/director.h"
#include "../model_to_save/screen_builder.h"

namespace s21 {
class ScreenController {
 public:
  ScreenController(const QString& modelName, const QString& fileType,
                   const QImage& image);
  void saveImage();

 private:
  QString modelName;
  QString fileType;
  QImage image;
};
}  // namespace s21

#endif  // SCREENCONTROLLER_H
