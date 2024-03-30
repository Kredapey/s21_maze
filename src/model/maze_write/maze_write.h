#ifndef A1_MAZE_SRC_MODEL_MAZE_WRITE_MAZE_WRITE_H_
#define A1_MAZE_SRC_MODEL_MAZE_WRITE_MAZE_WRITE_H_

#include "../maze_reader/maze_reader.h"

namespace s21 {

class MazeWrite {
 public:
  static void WriteMaze(Maze* maze, std::string path);
};

}  // namespace s21

#endif  // A1_MAZE_SRC_MODEL_MAZE_WRITE_MAZE_WRITE_H_