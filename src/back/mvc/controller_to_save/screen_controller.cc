#include <QDebug>
#include <QDir>

#include "screen_controller.h"

ScreenController::ScreenController(const QString& modelName,
                                   const QString& fileType, const QImage& image)
    : modelName(modelName), fileType(fileType), image(image) {}

void ScreenController::saveImage() {
  s21::Director director;
  s21::ScreenBuilder imageBuilder(modelName, fileType);

  director.setBuilder(&imageBuilder);
  QString fileName = director.construct();

  image.save(fileName);
}
