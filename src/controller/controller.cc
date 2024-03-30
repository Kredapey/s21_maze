#include "controller.h"

namespace s21 {

MazeController::MazeController(MazeFacade* maze_facade) {
  maze_facade_ = maze_facade;
}

void MazeController::BuildMaze(int rows, int cols) {
  maze_facade_->BuildMaze(rows, cols);
}

void MazeController::FindWay(int x_start, int y_start, int x_end, int y_end) {
  maze_facade_->FindWay(x_start, y_start, x_end, y_end);
}

void MazeController::ReadMaze(std::string path) {
  maze_facade_->ReadMaze(path);
}

void MazeController::WriteMaze(std::string path) {
  maze_facade_->WriteMaze(path);
}

std::vector<std::vector<int>> MazeController::GetRight() {
  return maze_facade_->GetRight();
}

std::vector<std::vector<int>> MazeController::GetBottom() {
  return maze_facade_->GetBottom();
}

std::vector<std::vector<int>> MazeController::GetWay() {
  return maze_facade_->GetWay();
}

int MazeController::GetCountWay() { return maze_facade_->GetCountWay(); }

int MazeController::GetFindWay() { return maze_facade_->GetFindWay(); }

}  // namespace s21