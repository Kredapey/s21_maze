#ifndef A1_MAZE_SRC_MODEL_WAY_WAY_H_
#define A1_MAZE_SRC_MODEL_WAY_WAY_H_

#include "../maze_builder/maze_builder.h"

namespace s21 {

class Way {
 public:
  static void FindWay(int x_start, int y_start, int x_end, int y_end,
                      Maze* maze);
  static int RecursiveWay(int x_start, int y_start, int x_end, int y_end,
                          Maze* maze);

 private:
  static void BuildClearWay(Maze* maze);
  static void FindWay(Maze* maze);
  static int CheckResults(std::vector<int>& results, int match, int y_start,
                          int x_start, Maze* maze);
  static void DeleteWay(Maze* maze);
};

}  // namespace s21

#endif  // A1_MAZE_SRC_MODEL_WAY_WAY_H_
