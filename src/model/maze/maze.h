#ifndef A1_MAZE_SRC_MODEL_MAZE_STRUCT_MAZE_H_
#define A1_MAZE_SRC_MODEL_MAZE_STRUCT_MAZE_H_

#include <cstddef>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <stdexcept>
#include <utility>
#include <vector>

namespace s21 {
struct Maze {
  int count_cell;
  int count_way;
  int rows;
  int cols;
  bool find_way;
  std::vector<std::vector<int>> right;
  std::vector<std::vector<int>> bottom;
  std::vector<std::vector<int>> cells;
  std::vector<std::vector<int>> way;
};
}  // namespace s21

#endif  // A1_MAZE_SRC_MODEL_MAZE_STRUCT_MAZE_H_
