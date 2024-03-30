#include "mainwindow.h"

namespace s21 {

MainWindow::MainWindow(s21::MazeController* maze_controller, QWidget* parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      maze_controller_(maze_controller) {
  ui->setupUi(this);
  scene_ = new Scene(maze_controller);
  ui->gridLayout->addWidget(scene_);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_clicked() {
  maze_controller_->BuildMaze(ui->rows_val->value(), ui->cols_val->value());
  scene_->PaintMaze(0);
}

void MainWindow::on_pushButton_2_clicked() {
  int x_start_val = ui->x_start_val->value();
  int y_start_val = ui->y_start_val->value();
  int x_end_val = ui->x_end_val->value();
  int y_end_val = ui->y_end_val->value();
  if (!maze_controller_->GetRight().empty() &&
      !maze_controller_->GetRight()[0].empty()) {
    int rows = maze_controller_->GetRight().size();
    int cols = maze_controller_->GetRight()[0].size();
    if (x_start_val < cols && y_start_val < rows && x_end_val < cols &&
        y_end_val < rows) {
      maze_controller_->FindWay(ui->x_start_val->value(),
                                ui->y_start_val->value(),
                                ui->x_end_val->value(), ui->y_end_val->value());
      if (maze_controller_->GetFindWay()) {
        scene_->PaintMaze(1);
      } else {
        QMessageBox msg;
        msg.setText("Can't find way");
        msg.exec();
      }
    } else {
      QMessageBox msg;
      msg.setText("Invalid Input");
      msg.exec();
    }
  }
}

void MainWindow::on_open_maze_button_clicked() {
  std::string path =
      QFileDialog::getOpenFileName(0, "Open file", QDir::homePath(),
                                   "Файлы формата .txt (*.txt)")
          .toStdString();
  try {
    if (path != "") {
      maze_controller_->ReadMaze(path);
      scene_->PaintMaze(0);
    }
  } catch (std::invalid_argument) {
    QMessageBox msg;
    msg.setText("Invalid Input");
    msg.exec();
  }
}

void MainWindow::on_write_maze_button_clicked() {
  std::string name_file =
      QFileDialog::getSaveFileName(this, tr("Save File"), "untitled.txt",
                                   tr("Text (*.txt)"))
          .toStdString();
  maze_controller_->WriteMaze(name_file);
}

}  // namespace s21
