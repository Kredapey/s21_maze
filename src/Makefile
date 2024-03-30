CC = g++
CFLAGS = -std=c++17 -Wall -Werror -Wextra
TEST_FLAGS = -lgtest
TESTS = maze_tests
REPORT = gcov_report
GCOV_REPORT = gcov/$(REPORT)
GCOV_INFO = $(GCOV_REPORT).info
GCOV_FLAGS  = --coverage -lcheck


.PHONY: all install dvi dist tests gcov_report uninstall clean

all: install tests gcov_report

maze.o:
	$(CC) $(CFLAGS) -g $(TEST_FLAGS) -c ./tests/$(TESTS).cc ./model/maze_builder/maze_builder.cc ./model/maze_reader/maze_reader.cc ./model/way/way.cc ./model/maze_write/maze_write.cc ./model/facade/facade.cc

maze.a: maze.o
	ar rcs maze.a maze_builder.o maze_reader.o way.o maze_write.o facade.o

tests: clean maze.a
	$(CC) $(CFLAGS) $(TESTS).o maze_builder.o maze_reader.o way.o maze_write.o facade.o -o $(TESTS) maze.a $(TEST_FLAGS)
	./$(TESTS)

gcov_report: tests
	$(CC) $(CFLAGS) --coverage ./tests/$(TESTS).cc ./model/maze_builder/maze_builder.cc ./model/maze_reader/maze_reader.cc ./model/way/way.cc ./model/maze_write/maze_write.cc ./model/facade/facade.cc -o gcov_report maze.a $(TEST_FLAGS)
	chmod +x *
	./gcov_report
	lcov -t "gcov_report" -o gcov_report.info --no-external --ignore-errors mismatch -c -d .
	genhtml -o report/ gcov_report.info
	open ./report/index.html

install: uninstall clean
	mkdir build
	cd view/config && qmake && make && make clean && rm Makefile && cd ../../ && mv view/config/view.app build/

open:
	open build/view.app/Contents/MacOS/view

check_leaks:
	CK_FORK=no leaks --atExit -- ./build/view.app/Contents/MacOS/view > logfile.log

dvi:
	open dvi/index.html

dist: install
	rm -rf ../MazeArch/
	mkdir ../MazeArch/
	cp -a **/ ./* Makefile ./build/view.app ../MazeArch
	cd ../ && tar -cvzf MazeArch.tar.gz MazeArch

valgrind: tests
	CK_FORK=no valgrind --track-origins=yes --leak-check=full --leak-resolution=med --show-leak-kinds=all -s ./$(TESTS)


uninstall:
	rm -rf ./build*

clean:
	rm -rf *.a
	rm -rf *.o
	rm -rf maze_tests
	rm -rf gcov_report
	rm -rf report
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
	rm -rf Tests/test
	rm -rf ../*.gz
	rm -rf ../MazeArch
	rm -rf gcov
	rm -rf test_viewer
	rm -rf RESULT.txt
	rm -rf ../src/view/*.o
	rm -rf build
	rm -rf *.log
	rm -rf ./view/*.o
	rm -rf ./view/config/*.pro.user
	rm -rf ./view/config/.qmake.stash

style:
	@echo "======= CHECK GOOGLE CODE STYLE ======="
	@sleep 1
	find . \( -name '*.h' -o -name '*.cc' \) -print0 | xargs -0 clang-format -n -style=Google
