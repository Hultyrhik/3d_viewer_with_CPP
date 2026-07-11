#ifndef PATH_BUILDER_H_
#define PATH_BUILDER_H_

#include <QDateTime>
#include <QString>
#include <QDir>

namespace s21 {
/**
 * @brief Abstract class for creating file paths.
 *
 * This class is used to create a path for saving a file.
 */
class FilePathBuilder {
 public:
  virtual ~FilePathBuilder() {}

  /**
   * @brief Set the directory where the file will be saved.
   */
  virtual void setSaveDirectory() = 0;

  /**
   * @brief Set the name of the file.
   */
  virtual void setFileName() = 0;

  /**
   * @brief Get the full path of the file.
   * @return The full path of the file.
   */
  QString getFilePath() const { return filePath; }

 protected:
  /**
   * @brief The full path of the file.
   */
  QString filePath;
};
}  // namespace s21
#endif  // PATH_BUILDER_H_
