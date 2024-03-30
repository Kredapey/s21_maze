#ifndef A1_MAZE_SRC_VIEW_MAINWINDOW_MAINWINDOW_H_
#define A1_MAZE_SRC_VIEW_MAINWINDOW_MAINWINDOW_H_

#include <QDir>
#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>

#include "../scene/scene.h"
#include "ui_mainwindow.h"

namespace s21 {

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(MazeController* maze_controller, QWidget* parent = nullptr);
  ~MainWindow();

 private slots:
  void on_pushButton_clicked();

  void on_pushButton_2_clicked();

  void on_open_maze_button_clicked();

  void on_write_maze_button_clicked();

 private:
  Ui::MainWindow* ui;
  Scene* scene_;
  MazeController* maze_controller_;
};

}  // namespace s21
#endif  // A1_MAZE_SRC_VIEW_MAINWINDOW_MAINWINDOW_H_
