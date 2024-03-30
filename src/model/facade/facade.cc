#include "facade.h"

namespace s21 {

MazeFacade::MazeFacade(Maze* maze) : maze_(maze) {}

void MazeFacade::BuildMaze(int rows, int cols) {
  MazeBuilder::BuildMaze(rows, cols, maze_);
}

void MazeFacade::FindWay(int x_start, int y_start, int x_end, int y_end) {
  Way::FindWay(x_start, y_start, x_end, y_end, maze_);
}

void MazeFacade::ReadMaze(std::string path) {
  MazeReader::ReadMaze(path, maze_);
}

void MazeFacade::WriteMaze(std::string path) {
  MazeWrite::WriteMaze(maze_, path);
}

std::vector<std::vector<int>> MazeFacade::GetRight() { return maze_->right; }

std::vector<std::vector<int>> MazeFacade::GetBottom() { return maze_->bottom; }

std::vector<std::vector<int>> MazeFacade::GetWay() { return maze_->way; }

int MazeFacade::GetCountWay() { return maze_->count_way; }

int MazeFacade::GetFindWay() { return maze_->find_way; }

}  // namespace s21
