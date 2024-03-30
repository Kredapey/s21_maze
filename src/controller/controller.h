#ifndef A1_MAZE_SRC_CONTROLLER_CONTROLLER_H_
#define A1_MAZE_SRC_CONTROLLER_CONTROLLER_H_

#include "../model/facade/facade.h"

namespace s21 {

class MazeController {
 public:
  MazeController(MazeFacade* maze_facade);
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
  MazeFacade* maze_facade_;
};

}  // namespace s21

#endif  // A1_MAZE_SRC_CONTROLLER_CONTROLLER_H_