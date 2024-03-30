#include "maze_reader.h"

namespace s21 {

void MazeReader::ReadMaze(std::string path, Maze* maze) {
  std::ifstream file_stream;
  file_stream.open(path);
  std::string str;
  int count_right = 0, count_bottom = 0;
  getline(file_stream, str);
  CheckRowsCols(str, maze);
  while (getline(file_stream, str)) {
    std::istringstream ss(str);
    int num = 0;
    if (count_right < maze->rows && str != "\0" && str != "\0") {
      for (int i = 0; i < maze->cols; i++) {
        ss >> num;
        if (num == 0 || num == 1) {
          maze->right[count_right][i] = num;
        } else {
          throw std::invalid_argument("Invalid Argument");
        }
      }
      count_right += 1;
    } else if (count_right >= maze->rows && count_bottom < maze->rows &&
               str != "\0" && str != "\0") {
      for (int i = 0; i < maze->cols; i++) {
        ss >> num;
        if (num == 0 || num == 1) {
          maze->bottom[count_bottom][i] = num;
        } else {
          throw std::invalid_argument("Invalid Argument");
        }
      }
      count_bottom += 1;
    }
  }
  CheckRightBottom(maze);
  file_stream.close();
}

void MazeReader::CheckRowsCols(std::string str, Maze* maze) {
  int count = 0;
  int num = 0;
  std::istringstream ss(str);
  while (ss >> num) {
    if (num > 0 && num <= 50) {
      if (count == 0) maze->rows = num;
      if (count == 1) maze->cols = num;
    } else {
      throw std::invalid_argument("Invalid Input");
    }
    ++count;
  }
  if (count != 2) throw std::invalid_argument("Invalid Input");
  MazeBuilder::BuildClearMaze(maze);
}

void MazeReader::CheckRightBottom(Maze* maze) {
  std::vector<int> bottom_vec;
  for (int i = 0; i < maze->cols; i++) {
    bottom_vec.push_back(1);
  }
  if (maze->bottom[maze->rows - 1] != bottom_vec)
    throw std::invalid_argument("Invalid Input");
  for (int i = 0; i < maze->rows; i++) {
    if (maze->right[i][maze->cols - 1] != 1)
      throw std::invalid_argument("Invalid Input");
  }
}

}  // namespace s21
