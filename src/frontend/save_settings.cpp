#include <QSettings>

#include "display_window.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

/**
 * @brief Writes the settings to a file
 *
 * The settings include the size and position of the main window, the path to
 * the file, the background, line and point colors, the point size, line width,
 * point type, line type and projection type.
 */
void MainWindow::writeSettings() {
  QSettings settings("settings_demo.conf", QSettings::IniFormat);
  settings.beginGroup("my_data");
  settings.setValue("size", size());
  settings.setValue("pos", pos());
  settings.setValue("path_to_file",
                    ui->display_window->my_data.path_to_file.c_str());
  settings.beginWriteArray("datas");
  for (int i = 0; i < 3; i++) {
    settings.setArrayIndex(i);
    settings.setValue("background_color",
                      ui->display_window->my_data.background_color[i]);
    settings.setValue("line_color", ui->display_window->my_data.line_color[i]);
    settings.setValue("point_color",
                      ui->display_window->my_data.point_color[i]);
  }
  settings.endArray();
  settings.setValue("point_size", ui->display_window->my_data.point_size);
  settings.setValue("line_width", ui->display_window->my_data.line_width);
  settings.setValue("point_type", ui->display_window->my_data.point_type);
  settings.setValue("line_type", ui->display_window->my_data.line_type);
  settings.setValue("projection_type",
                    ui->display_window->my_data.projection_type);
  settings.endGroup();
}

/**
 * @brief Reads the settings from a file
 *
 * The settings include the size and position of the main window, the path to
 * the file, the background, line and point colors, the point size, line width,
 * point type, line type and projection type.
 *
 * If the file does not exist, the method does nothing.
 */
void MainWindow::readSettings() {
  if (QFile("settings_demo.conf").exists()) {
    QSettings settings("settings_demo.conf", QSettings::IniFormat);
    settings.beginGroup("my_data");
    resize(settings.value("size").toSize());
    move(settings.value("pos").toPoint());
    ui->display_window->my_data.path_to_file =
        settings.value("path_to_file").toString().toStdString();
    settings.beginReadArray("datas");
    for (int i = 0; i < 3; i++) {
      settings.setArrayIndex(i);
      ui->display_window->my_data.background_color[i] =
          settings.value("background_color").toDouble();
      ui->display_window->my_data.line_color[i] =
          settings.value("line_color").toDouble();
      ui->display_window->my_data.point_color[i] =
          settings.value("point_color").toDouble();
    }
    settings.endArray();
    ui->display_window->my_data.point_type =
        static_cast<Point_type>(settings.value("point_type").toInt());
    ui->display_window->my_data.line_type =
        static_cast<Line_type>(settings.value("line_type").toInt());
    ui->display_window->my_data.projection_type =
        static_cast<Projection_type>(settings.value("projection_type").toInt());
    ui->display_window->my_data.point_size =
        settings.value("point_size").toInt();
    ui->display_window->my_data.line_width =
        settings.value("line_width").toInt();
    settings.endGroup();
    if (ui->display_window->my_data.path_to_file.empty() == false) {
      read_obj_file();
      write_to_ui();
    }
  }
}
