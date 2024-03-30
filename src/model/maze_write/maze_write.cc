#include "maze_write.h"

namespace s21 {

void MazeWrite::WriteMaze(Maze* maze, std::string path) {
  std::ofstream file;
  file.open(path);
  if (file.is_open()) {
    if (maze->rows != 0 && maze->cols != 0) {
      file << maze->rows << " ";
      file << maze->cols << std::endl;
      for (int i = 0; i < maze->rows; ++i) {
        for (int j = 0; j < maze->cols; ++j) {
          file << maze->right[i][j] << " ";
        }
        file << std::endl;
      }
      file << std::endl;
      for (int i = 0; i < maze->rows; ++i) {
        for (int j = 0; j < maze->cols; ++j) {
          file << maze->bottom[i][j] << " ";
        }
        file << std::endl;
      }
    }
  }
  file.close();
}

}  // namespace s21