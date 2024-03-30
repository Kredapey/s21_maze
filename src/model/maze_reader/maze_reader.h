#ifndef A1_MAZE_SRC_MODEL_MAZE_READER_MAZE_READER_H_
#define A1_MAZE_SRC_MODEL_MAZE_READER_MAZE_READER_H_

#include "../way/way.h"

namespace s21 {

class MazeReader {
 public:
  static void ReadMaze(std::string path, Maze* maze);

 private:
  static void CheckRowsCols(std::string str, Maze* maze);
  static void CheckRightBottom(Maze* maze);
};

}  // namespace s21

#endif  // A1_MAZE_SRC_MODEL_MAZE_READER_MAZE_READER_H_