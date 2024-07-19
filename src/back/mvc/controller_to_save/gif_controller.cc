#include "gif_controller.h"

#include <QDebug>
#include <QDir>
#include <chrono>
#include <thread>

#include "../../../gif/gif.hpp"

GIFController::GIFController(const QString& modelName, uint8_t* image,
                             int width, int height)
    : modelName(modelName), image(image), width(width), height(height) {}

void GIFController::saveGIF() {
  s21::Director director;
  s21::GIFBuilder gifBuilder(modelName);

  director.setBuilder(&gifBuilder);
  QString fileName = director.construct();

  int delay = 100;
  GifWriter g;
  GifBegin(&g, fileName.toStdString().c_str(), width, height, delay);

  for (int timer = 0; timer <= 5000; timer += delay) {
    QImage tempImage(image, width, height, QImage::Format_ARGB32);
    QRect sourceRect((width - 640) / 2, (height - 480) / 2, 640, 480);
    tempImage = tempImage.copy(sourceRect);
    GifWriteFrame(&g, tempImage.bits(), 640, 480, 1);
    std::this_thread::sleep_for(std::chrono::milliseconds(delay));
  }

  qDebug() << "Gif is ready";
  GifEnd(&g);
}
