#ifndef SCREE_BUILDER_H_
#define SCREE_BUILDER_H_

#include "path_builder.h"

namespace s21 {
class ScreenBuilder : public FilePathBuilder {
 public:
  ScreenBuilder(const QString& modelName, const QString& fileType)
      : modelName(modelName), fileType(fileType) {}
  void setSaveDirectory() override {
    QString saveDirectory = "../../misc/img/";
    QDir dir(saveDirectory);
    if (!dir.exists()) {
      dir.mkpath(".");
    }
    filePath = saveDirectory + "/";
  }
  void setFileName() override {
    QTime date = QTime::currentTime();
    filePath.append(date.toString("hh_mm_ss_"));
    filePath.append(modelName);
    filePath.append(fileType);
  }

 private:
  QString modelName;
  QString fileType;
};

}  // namespace s21

#endif  // SCREE_BUILDER_H_