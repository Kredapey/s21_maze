#include "maze_builder.h"

namespace s21 {

bool MazeBuilder::RandomBool() { return std::rand() % 2; }

void MazeBuilder::BuildMaze(int rows, int cols, Maze* maze) {
  if (rows == maze->rows && cols == maze->cols) {
    ClearMaze(maze);
  } else {
    maze->rows = rows;
    maze->cols = cols;
    BuildClearMaze(maze);
  }
  for (int i = 0; i < maze->rows - 1; i++) {
    NumCellSet(maze->cells[i], maze);
    BuildRightWalls(maze->right[i], i, maze);
    BuildBottomWalls(maze->bottom[i], i, maze);
    BuildNextRow(maze->cells[i], maze->cells[i + 1], i, maze);
  }
  if (rows > 1) BuildLastRow(maze);
}

void MazeBuilder::BuildLastRow(Maze* maze) {
  BuildRightWalls(maze->right[maze->rows - 1], maze->rows - 1, maze);
  for (int i = 0; i < maze->cols - 1; i++) {
    if (maze->cells[maze->rows - 1][i] != maze->cells[maze->rows - 1][i + 1] &&
        maze->right[maze->rows - 1][i]) {
      maze->right[maze->rows - 1][i] = 0;
      MergeSet(maze->rows - 1, i, maze);
    }
  }
}

void MazeBuilder::BuildNextRow(std::vector<int> row, std::vector<int>& next_row,
                               int num_row, Maze* maze) {
  next_row = row;
  for (int i = 0; i < maze->cols; i++) {
    if (maze->bottom[num_row][i] == 1) {
      next_row[i] = ++maze->count_cell;
    }
  }
}

void MazeBuilder::BuildRightWalls(std::vector<int>& row, int num_row,
                                  Maze* maze) {
  for (int i = 0; i < maze->cols - 1; i++) {
    bool decision = RandomBool();
    if (decision || maze->cells[num_row][i] == maze->cells[num_row][i + 1]) {
      row[i] = 1;
    } else {
      MergeSet(num_row, i, maze);
    }
  }
}

void MazeBuilder::BuildBottomWalls(std::vector<int>& row, int num_row,
                                   Maze* maze) {
  for (int i = 0; i < maze->cols; i++) {
    bool decision = RandomBool();
    if (decision && CalcNumSet(maze->cells[num_row], maze->cells[num_row][i],
                               num_row, maze) > 1) {
      row[i] = 1;
    }
  }
}

int MazeBuilder::CalcNumSet(std::vector<int> row, int set, int num_row,
                            Maze* maze) {
  int result = 0;
  for (int i = 0; i < maze->cols; i++) {
    if (row[i] == set && maze->bottom[num_row][i] == 0) {
      result++;
    }
  }
  return result;
}

void MazeBuilder::MergeSet(int num_row, int index, Maze* maze) {
  int mut_set = maze->cells[num_row][index + 1];
  for (int i = 0; i < maze->cols; i++) {
    if (maze->cells[num_row][i] == mut_set) {
      maze->cells[num_row][i] = maze->cells[num_row][index];
    }
  }
}

void MazeBuilder::NumCellSet(std::vector<int>& row, Maze* maze) {
  for (int i = 0; i < maze->cols; i++) {
    if (row[i] == 0) row[i] = ++maze->count_cell;
  }
}

void MazeBuilder::BuildClearMaze(Maze* maze) {
  if (!maze->right.empty() && !maze->bottom.empty() && !maze->cells.empty())
    DeleteMaze(maze);
  std::vector<int> clear_vector;
  std::vector<int> clear_vector_right;
  std::vector<int> clear_vector_bot;
  for (int i = 0; i < maze->cols; i++) {
    clear_vector.push_back(0);
    clear_vector_bot.push_back(1);
    if (i == maze->cols - 1)
      clear_vector_right.push_back(1);
    else
      clear_vector_right.push_back(0);
  }
  for (int i = 0; i < maze->rows; i++) {
    maze->right.push_back(clear_vector_right);
    maze->cells.push_back(clear_vector);
    if (i == maze->rows - 1)
      maze->bottom.push_back(clear_vector_bot);
    else
      maze->bottom.push_back(clear_vector);
  }
}

void MazeBuilder::DeleteMaze(Maze* maze) {
  for (unsigned long i = 0; i < maze->right.size(); i++) {
    maze->right[i].clear();
    maze->cells[i].clear();
    maze->bottom[i].clear();
  }
  maze->right.clear();
  maze->cells.clear();
  maze->bottom.clear();
  maze->count_cell = 0;
}

void MazeBuilder::ClearMaze(Maze* maze) {
  for (int i = 0; i < maze->rows; ++i) {
    for (int j = 0; j < maze->cols; ++j) {
      if (j == maze->cols - 1)
        maze->right[i][j] = 1;
      else
        maze->right[i][j] = 0;
      if (i == maze->rows - 1)
        maze->bottom[i][j] = 1;
      else
        maze->bottom[i][j] = 0;
      maze->cells[i][j] = 0;
    }
  }
  maze->count_cell = 0;
}

}  // namespace s21
