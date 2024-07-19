#ifndef PATH_BUILDER_H_
#define PATH_BUILDER_H_

#include <QDateTime>
#include <QString>
#include <QDir>

namespace s21 {
class FilePathBuilder {
 public:
  virtual ~FilePathBuilder() {}
  virtual void setSaveDirectory() = 0;
  virtual void setFileName() = 0;
  QString getFilePath() const { return filePath; }

 protected:
  QString filePath;
};
}  // namespace s21
#endif  // PATH_BUILDER_H_
