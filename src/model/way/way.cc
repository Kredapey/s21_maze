#include "way.h"

namespace s21 {

void Way::FindWay(int x_start, int y_start, int x_end, int y_end, Maze* maze) {
  BuildClearWay(maze);
  maze->way[y_start][x_start] = -1;
  RecursiveWay(x_start, y_start, x_end, y_end, maze);
  maze->way[y_start][x_start] = 1;
}

int Way::RecursiveWay(int x_start, int y_start, int x_end, int y_end,
                      Maze* maze) {
  std::vector<int> results;
  int result = 0, match = 0;
  if (x_start == x_end && y_start == y_end) {
    if (maze->way[y_start][x_start] != -1)
      maze->count_way = maze->way[y_start][x_start];
    else
      maze->count_way = 1;
    maze->find_way = true;
    return 1;
  }
  int add = 0;
  if (maze->way[y_start][x_start] != -1) {
    add = maze->way[y_start][x_start] + 1;
  } else {
    add = 2;
  }
  if (x_start > 0 && !maze->right[y_start][x_start - 1] &&
      maze->way[y_start][x_start - 1] == 0) {
    match += 1;
    maze->way[y_start][x_start - 1] = add;
    results.push_back(RecursiveWay(x_start - 1, y_start, x_end, y_end, maze));
  }
  if (!maze->right[y_start][x_start] && maze->way[y_start][x_start + 1] == 0) {
    match += 1;
    maze->way[y_start][x_start + 1] = add;
    results.push_back(RecursiveWay(x_start + 1, y_start, x_end, y_end, maze));
  }
  if (y_start > 0 && !maze->bottom[y_start - 1][x_start] &&
      maze->way[y_start - 1][x_start] == 0) {
    match += 1;
    maze->way[y_start - 1][x_start] = add;
    results.push_back(RecursiveWay(x_start, y_start - 1, x_end, y_end, maze));
  }
  if (!maze->bottom[y_start][x_start] && maze->way[y_start + 1][x_start] == 0) {
    match += 1;
    maze->way[y_start + 1][x_start] = add;
    results.push_back(RecursiveWay(x_start, y_start + 1, x_end, y_end, maze));
  }
  result = CheckResults(results, match, y_start, x_start, maze);
  return result;
}

int Way::CheckResults(std::vector<int>& results, int match, int y_start,
                      int x_start, Maze* maze) {
  int result = 0;
  if (match == 0) {
    maze->way[y_start][x_start] = -2;
    result = 2;
  }
  if (match == 1 && results.back() == 2) {
    maze->way[y_start][x_start] = -2;
    result = 2;
  }
  if (match > 1 && results.back() == 2) {
    for (int i = 0; i < match; i++) {
      if (results.back() != 2) {
        result = 0;
        results.pop_back();
        break;
      } else {
        result = 2;
        results.pop_back();
      }
    }
    if (result == 2) {
      maze->way[y_start][x_start] = -2;
    }
  }
  return result;
}

void Way::BuildClearWay(Maze* maze) {
  if (!maze->way.empty()) DeleteWay(maze);
  std::vector<int> clear_vec;
  for (int i = 0; i < maze->cols; i++) {
    clear_vec.push_back(0);
  }
  for (int i = 0; i < maze->rows; i++) {
    maze->way.push_back(clear_vec);
  }
}

void Way::DeleteWay(Maze* maze) {
  for (unsigned long i = 0; i < maze->way.size(); i++) {
    maze->way[i].clear();
  }
  maze->way.clear();
  maze->count_way = 0;
  maze->find_way = false;
}

}  // namespace s21
