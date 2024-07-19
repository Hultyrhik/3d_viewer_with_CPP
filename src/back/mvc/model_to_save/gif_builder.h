#ifndef GIF_BUILDER_H_
#define GIF_BUILDER_H_

#include "path_builder.h"

namespace s21 {
class GIFBuilder : public FilePathBuilder {
 public:
  GIFBuilder(const QString& modelName) : modelName(modelName) {}
  void setSaveDirectory() override {
    QString saveDirectory = "../../misc/gif/";
    QDir dir(saveDirectory);
    if (!dir.exists()) {
      dir.mkpath(".");
    }
    filePath = saveDirectory + "/";
  }
  void setFileName() override {
    QString fileType = ".gif";
    QTime date = QTime::currentTime();
    filePath.append(date.toString("hh_mm_ss_"));
    filePath.append(modelName);
    filePath.append(fileType);
  }

 private:
  QString modelName;
};

}  // namespace s21

#endif  // GIF_BUILDER_H_