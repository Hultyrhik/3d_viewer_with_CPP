#ifndef SCREENCONTROLLER_H
#define SCREENCONTROLLER_H

#include <QImage>
#include <QString>

#include "../model_to_save/director.h"
#include "../model_to_save/screen_builder.h"

namespace s21 {
/**
 * @brief Class for saving a screen image.
 *
 * This class is used to save a screen image. It takes a model name, a file
 * type, and an image as parameters in the constructor. The saveImage method is
 * used to save the image.
 */
class ScreenController {
 public:
  /**
   * @brief Construct a new ScreenController object.
   *
   * @param modelName The name of the model.
   * @param fileType The type of the file (e.g. ".png").
   * @param image The image to save.
   */
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
