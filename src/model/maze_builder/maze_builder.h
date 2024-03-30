#ifndef A1_MAZE_SRC_MODEL_MAZE_BUILDER_MAZE_BUILDER_H_
#define A1_MAZE_SRC_MODEL_MAZE_BUILDER_MAZE_BUILDER_H_

#include "../maze/maze.h"

namespace s21 {
class MazeBuilder {
 public:
  static void BuildMaze(int rows, int cols, Maze* maze);
  static void BuildClearMaze(Maze* maze);

 private:
  static bool RandomBool();
  static void NumCellSet(std::vector<int>& row, Maze* maze);
  static void BuildRightWalls(std::vector<int>& row, int num_row, Maze* maze);
  static void BuildBottomWalls(std::vector<int>& row, int num_row, Maze* maze);
  static void MergeSet(int num_row, int index, Maze* maze);
  static int CalcNumSet(std::vector<int> row, int set, int num_row, Maze* maze);
  static void BuildNextRow(std::vector<int> row, std::vector<int>& next_row,
                           int num_row, Maze* maze);
  static void BuildLastRow(Maze* maze);
  static void ClearMaze(Maze* maze);
  static void DeleteMaze(Maze* maze);
};

}  // namespace s21

#endif  // A1_MAZE_SRC_MODEL_MAZE_BUILDER_MAZE_BUILDER_H_
