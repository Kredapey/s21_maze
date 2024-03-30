#include <gtest/gtest.h>

#include "../model/facade/facade.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(read_maze, test1) {
  s21::Maze maze = {};
  s21::MazeFacade maze_facade(&maze);
  maze_facade.ReadMaze("./tests/test_maze/maze.txt");
  EXPECT_EQ(maze.rows, 4);
  EXPECT_EQ(maze.cols, 4);
  EXPECT_EQ(maze.right[0][0], 0);
  EXPECT_EQ(maze.right[0][1], 0);
  EXPECT_EQ(maze.right[0][2], 0);
  EXPECT_EQ(maze.right[0][3], 1);
  EXPECT_EQ(maze.right[1][0], 1);
  EXPECT_EQ(maze.right[1][1], 0);
  EXPECT_EQ(maze.right[1][2], 1);
  EXPECT_EQ(maze.right[1][3], 1);
  EXPECT_EQ(maze.right[2][0], 0);
  EXPECT_EQ(maze.right[2][1], 1);
  EXPECT_EQ(maze.right[2][2], 0);
  EXPECT_EQ(maze.right[2][3], 1);
  EXPECT_EQ(maze.right[3][0], 0);
  EXPECT_EQ(maze.right[3][1], 0);
  EXPECT_EQ(maze.right[3][2], 0);
  EXPECT_EQ(maze.right[3][3], 1);
  EXPECT_EQ(maze.bottom[0][0], 1);
  EXPECT_EQ(maze.bottom[0][1], 0);
  EXPECT_EQ(maze.bottom[0][2], 1);
  EXPECT_EQ(maze.bottom[0][3], 0);
  EXPECT_EQ(maze.bottom[1][0], 0);
  EXPECT_EQ(maze.bottom[1][1], 0);
  EXPECT_EQ(maze.bottom[1][2], 1);
  EXPECT_EQ(maze.bottom[1][3], 0);
  EXPECT_EQ(maze.bottom[2][0], 1);
  EXPECT_EQ(maze.bottom[2][1], 1);
  EXPECT_EQ(maze.bottom[2][2], 0);
  EXPECT_EQ(maze.bottom[2][3], 1);
  EXPECT_EQ(maze.bottom[3][0], 1);
  EXPECT_EQ(maze.bottom[3][1], 1);
  EXPECT_EQ(maze.bottom[3][2], 1);
  EXPECT_EQ(maze.bottom[3][3], 1);
}

TEST(build_maze, test1) {
  s21::Maze maze = {};
  s21::MazeFacade maze_facade(&maze);
  maze_facade.BuildMaze(4, 4);
  EXPECT_EQ(maze.rows, 4);
  EXPECT_EQ(maze.cols, 4);
  EXPECT_EQ(maze.right[0][3], 1);
  EXPECT_EQ(maze.right[1][3], 1);
  EXPECT_EQ(maze.right[2][3], 1);
  EXPECT_EQ(maze.right[3][3], 1);
  EXPECT_EQ(maze.bottom[3][0], 1);
  EXPECT_EQ(maze.bottom[3][1], 1);
  EXPECT_EQ(maze.bottom[3][2], 1);
  EXPECT_EQ(maze.bottom[3][3], 1);
}

TEST(build_maze, test2) {
  s21::Maze maze = {};
  s21::MazeFacade maze_facade(&maze);
  maze_facade.BuildMaze(4, 4);
  EXPECT_EQ(maze.rows, 4);
  EXPECT_EQ(maze.cols, 4);
  EXPECT_EQ(maze.right[0][3], 1);
  EXPECT_EQ(maze.right[1][3], 1);
  EXPECT_EQ(maze.right[2][3], 1);
  EXPECT_EQ(maze.right[3][3], 1);
  EXPECT_EQ(maze.bottom[3][0], 1);
  EXPECT_EQ(maze.bottom[3][1], 1);
  EXPECT_EQ(maze.bottom[3][2], 1);
  EXPECT_EQ(maze.bottom[3][3], 1);
  maze_facade.BuildMaze(4, 4);
  EXPECT_EQ(maze.rows, 4);
  EXPECT_EQ(maze.cols, 4);
  EXPECT_EQ(maze.right[0][3], 1);
  EXPECT_EQ(maze.right[1][3], 1);
  EXPECT_EQ(maze.right[2][3], 1);
  EXPECT_EQ(maze.right[3][3], 1);
  EXPECT_EQ(maze.bottom[3][0], 1);
  EXPECT_EQ(maze.bottom[3][1], 1);
  EXPECT_EQ(maze.bottom[3][2], 1);
  EXPECT_EQ(maze.bottom[3][3], 1);
}

TEST(build_maze, test3) {
  s21::Maze maze = {};
  s21::MazeFacade maze_facade(&maze);
  maze_facade.BuildMaze(4, 4);
  EXPECT_EQ(maze.rows, 4);
  EXPECT_EQ(maze.cols, 4);
  EXPECT_EQ(maze.right[0][3], 1);
  EXPECT_EQ(maze.right[1][3], 1);
  EXPECT_EQ(maze.right[2][3], 1);
  EXPECT_EQ(maze.right[3][3], 1);
  EXPECT_EQ(maze.bottom[3][0], 1);
  EXPECT_EQ(maze.bottom[3][1], 1);
  EXPECT_EQ(maze.bottom[3][2], 1);
  EXPECT_EQ(maze.bottom[3][3], 1);
  maze_facade.BuildMaze(5, 5);
  EXPECT_EQ(maze.rows, 5);
  EXPECT_EQ(maze.cols, 5);
  EXPECT_EQ(maze.right[0][4], 1);
  EXPECT_EQ(maze.right[1][4], 1);
  EXPECT_EQ(maze.right[2][4], 1);
  EXPECT_EQ(maze.right[3][4], 1);
  EXPECT_EQ(maze.right[4][4], 1);
  EXPECT_EQ(maze.bottom[4][0], 1);
  EXPECT_EQ(maze.bottom[4][1], 1);
  EXPECT_EQ(maze.bottom[4][2], 1);
  EXPECT_EQ(maze.bottom[4][3], 1);
  EXPECT_EQ(maze.bottom[4][4], 1);
}

TEST(find_way, test1) {
  s21::Maze maze = {};
  s21::MazeFacade maze_facade(&maze);
  maze_facade.ReadMaze("./tests/test_maze/maze.txt");
  maze_facade.FindWay(0, 0, 3, 3);
  EXPECT_EQ(maze.rows, 4);
  EXPECT_EQ(maze.cols, 4);
  EXPECT_EQ(maze.way[0][0], 1);
  EXPECT_EQ(maze.way[0][1], 2);
  EXPECT_EQ(maze.way[0][2], 3);
  EXPECT_EQ(maze.way[0][3], 4);
  EXPECT_EQ(maze.way[1][3], 5);
  EXPECT_EQ(maze.way[2][3], 6);
  EXPECT_EQ(maze.way[2][2], 7);
  EXPECT_EQ(maze.way[3][2], 8);
  EXPECT_EQ(maze.way[3][3], 9);
}

TEST(find_way, test2) {
  s21::Maze maze = {};
  s21::MazeFacade maze_facade(&maze);
  maze_facade.BuildMaze(5, 5);
  maze_facade.FindWay(0, 0, 4, 4);
  maze_facade.ReadMaze("./tests/test_maze/maze.txt");
  maze_facade.FindWay(0, 0, 3, 3);
  EXPECT_EQ(maze.rows, 4);
  EXPECT_EQ(maze.cols, 4);
  EXPECT_EQ(maze.way[0][0], 1);
  EXPECT_EQ(maze.way[0][1], 2);
  EXPECT_EQ(maze.way[0][2], 3);
  EXPECT_EQ(maze.way[0][3], 4);
  EXPECT_EQ(maze.way[1][3], 5);
  EXPECT_EQ(maze.way[2][3], 6);
  EXPECT_EQ(maze.way[2][2], 7);
  EXPECT_EQ(maze.way[3][2], 8);
  EXPECT_EQ(maze.way[3][3], 9);
}

TEST(get_tests, test1) {
  s21::Maze maze = {};
  s21::MazeFacade maze_facade(&maze);
  maze_facade.ReadMaze("./tests/test_maze/maze.txt");
  maze_facade.FindWay(0, 0, 3, 3);
  EXPECT_EQ(maze_facade.GetCountWay(), 9);
  std::vector<std::vector<int>> right = maze_facade.GetRight();
  std::vector<std::vector<int>> bottom = maze_facade.GetBottom();
  std::vector<std::vector<int>> way = maze_facade.GetWay();
  int find_way = maze_facade.GetFindWay();
  EXPECT_EQ(find_way, 1);

  EXPECT_EQ(way[0][0], 1);
  EXPECT_EQ(way[0][1], 2);
  EXPECT_EQ(way[0][2], 3);
  EXPECT_EQ(way[0][3], 4);
  EXPECT_EQ(way[1][3], 5);
  EXPECT_EQ(way[2][3], 6);
  EXPECT_EQ(way[2][2], 7);
  EXPECT_EQ(way[3][2], 8);
  EXPECT_EQ(way[3][3], 9);

  EXPECT_EQ(right[0][0], 0);
  EXPECT_EQ(right[0][1], 0);
  EXPECT_EQ(right[0][2], 0);
  EXPECT_EQ(right[0][3], 1);
  EXPECT_EQ(right[1][0], 1);
  EXPECT_EQ(right[1][1], 0);
  EXPECT_EQ(right[1][2], 1);
  EXPECT_EQ(right[1][3], 1);
  EXPECT_EQ(right[2][0], 0);
  EXPECT_EQ(right[2][1], 1);
  EXPECT_EQ(right[2][2], 0);
  EXPECT_EQ(right[2][3], 1);
  EXPECT_EQ(right[3][0], 0);
  EXPECT_EQ(right[3][1], 0);
  EXPECT_EQ(right[3][2], 0);
  EXPECT_EQ(right[3][3], 1);
  EXPECT_EQ(bottom[0][0], 1);
  EXPECT_EQ(bottom[0][1], 0);
  EXPECT_EQ(bottom[0][2], 1);
  EXPECT_EQ(bottom[0][3], 0);
  EXPECT_EQ(bottom[1][0], 0);
  EXPECT_EQ(bottom[1][1], 0);
  EXPECT_EQ(bottom[1][2], 1);
  EXPECT_EQ(bottom[1][3], 0);
  EXPECT_EQ(bottom[2][0], 1);
  EXPECT_EQ(bottom[2][1], 1);
  EXPECT_EQ(bottom[2][2], 0);
  EXPECT_EQ(bottom[2][3], 1);
  EXPECT_EQ(bottom[3][0], 1);
  EXPECT_EQ(bottom[3][1], 1);
  EXPECT_EQ(bottom[3][2], 1);
  EXPECT_EQ(bottom[3][3], 1);
}

TEST(write_maze, test1) {
  s21::Maze maze;
  s21::MazeFacade maze_facade(&maze);
  maze_facade.ReadMaze("./tests/test_maze/maze.txt");
  maze_facade.WriteMaze("./tests/test_maze/write_maze.txt");
  maze_facade.ReadMaze("./tests/test_maze/write_maze.txt");
  EXPECT_EQ(maze.rows, 4);
  EXPECT_EQ(maze.cols, 4);
  EXPECT_EQ(maze.right[0][0], 0);
  EXPECT_EQ(maze.right[0][1], 0);
  EXPECT_EQ(maze.right[0][2], 0);
  EXPECT_EQ(maze.right[0][3], 1);
  EXPECT_EQ(maze.right[1][0], 1);
  EXPECT_EQ(maze.right[1][1], 0);
  EXPECT_EQ(maze.right[1][2], 1);
  EXPECT_EQ(maze.right[1][3], 1);
  EXPECT_EQ(maze.right[2][0], 0);
  EXPECT_EQ(maze.right[2][1], 1);
  EXPECT_EQ(maze.right[2][2], 0);
  EXPECT_EQ(maze.right[2][3], 1);
  EXPECT_EQ(maze.right[3][0], 0);
  EXPECT_EQ(maze.right[3][1], 0);
  EXPECT_EQ(maze.right[3][2], 0);
  EXPECT_EQ(maze.right[3][3], 1);
  EXPECT_EQ(maze.bottom[0][0], 1);
  EXPECT_EQ(maze.bottom[0][1], 0);
  EXPECT_EQ(maze.bottom[0][2], 1);
  EXPECT_EQ(maze.bottom[0][3], 0);
  EXPECT_EQ(maze.bottom[1][0], 0);
  EXPECT_EQ(maze.bottom[1][1], 0);
  EXPECT_EQ(maze.bottom[1][2], 1);
  EXPECT_EQ(maze.bottom[1][3], 0);
  EXPECT_EQ(maze.bottom[2][0], 1);
  EXPECT_EQ(maze.bottom[2][1], 1);
  EXPECT_EQ(maze.bottom[2][2], 0);
  EXPECT_EQ(maze.bottom[2][3], 1);
  EXPECT_EQ(maze.bottom[3][0], 1);
  EXPECT_EQ(maze.bottom[3][1], 1);
  EXPECT_EQ(maze.bottom[3][2], 1);
  EXPECT_EQ(maze.bottom[3][3], 1);
}
