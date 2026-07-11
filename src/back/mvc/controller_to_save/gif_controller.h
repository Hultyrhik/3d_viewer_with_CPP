#ifndef GIFCONTROLLER_H
#define GIFCONTROLLER_H

#include <QImage>
#include <QString>

#include "../model_to_save/director.h"
#include "../model_to_save/gif_builder.h"

namespace s21 {
/**
 * @brief Class for saving a GIF image.
 *
 * This class is used to save a GIF image. It takes a model name, a pointer to
 * the image data, the width, and the height of the image as parameters in the
 * constructor. The saveGIF method is used to save the GIF image.
 */
class GIFController {
 public:
  /**
   * @brief Construct a new GIFController object.
   *
   * @param modelName The name of the model.
   * @param image A pointer to the image data.
   * @param width The width of the image.
   * @param height The height of the image.
   */
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
