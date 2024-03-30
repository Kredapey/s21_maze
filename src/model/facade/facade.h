#ifndef A1_MAZE_SRC_MODEL_FACADE_FACADE_H_
#define A1_MAZE_SRC_MODEL_FACADE_FACADE_H_

#include "../maze_write/maze_write.h"

namespace s21 {

class MazeFacade {
 public:
  MazeFacade(Maze* maze);

  void BuildMaze(int rows, int cols);
  void FindWay(int x_start, int y_start, int x_end, int y_end);
  void ReadMaze(std::string path);
  void WriteMaze(std::string path);
  std::vector<std::vector<int>> GetRight();
  std::vector<std::vector<int>> GetBottom();
  std::vector<std::vector<int>> GetWay();
  int GetCountWay();
  int GetFindWay();

 private:
  Maze* maze_;
};

}  // namespace s21

#endif  // A1_MAZE_SRC_MODEL_FACADE_FACADE_H_