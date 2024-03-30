#include <QApplication>

#include "./view/mainwindow/mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21::Maze maze = {};
  s21::MazeFacade maze_facade(&maze);
  s21::MazeController maze_controller(&maze_facade);
  s21::MainWindow w(&maze_controller);
  w.show();
  return a.exec();
}
