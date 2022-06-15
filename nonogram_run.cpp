#include "sudoku.h"
#include <chrono>
#include <iostream>

int UNSOLVED_PUZZLE[81] = {0, 0, 4, 3, 0, 0, 2, 0, 9, 0, 0, 5, 0, 0, 9, 0, 0,
                           1, 0, 7, 0, 0, 6, 0, 0, 4, 3, 0, 0, 6, 0, 0, 2, 0,
                           8, 7, 1, 9, 0, 0, 0, 7, 4, 0, 0, 0, 5, 0, 0, 8, 3,
                           0, 0, 0, 6, 0, 0, 0, 0, 0, 1, 0, 5, 0, 0, 3, 5, 0,
                           8, 6, 9, 0, 0, 4, 2, 9, 1, 0, 3, 0, 0};

int SOLVED_PUZZLE[81] = {8, 6, 4, 3, 7, 1, 2, 5, 9, 3, 2, 5, 8, 4, 9, 7, 6,
                         1, 9, 7, 1, 2, 6, 5, 8, 4, 3, 4, 3, 6, 1, 9, 2, 5,
                         8, 7, 1, 9, 8, 6, 5, 7, 4, 3, 2, 2, 5, 7, 4, 8, 3,
                         9, 1, 6, 6, 8, 9, 7, 3, 4, 1, 2, 5, 7, 1, 3, 5, 2,
                         8, 6, 9, 4, 5, 4, 2, 9, 1, 6, 3, 7, 8};

int EVIL_PUZZLE[81] = {9, 0, 0, 0, 5, 0, 0, 0, 0, 0, 3, 5, 0, 0, 2, 0, 0,
                       7, 8, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 9, 0, 0, 0, 0,
                       0, 0, 0, 0, 0, 0, 0, 8, 0, 4, 0, 0, 5, 7, 0, 4, 0,
                       6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 2, 0, 6, 4, 0, 8,
                       0, 7, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0};
int main() {
  std::cout << "BEFORE SOLVING" << std::endl;
  prettyPrint(EVIL_PUZZLE);
  int please_solve[81];
  int solved_puzzle[81];
  copyPuzzle(EVIL_PUZZLE, please_solve);
  std::chrono::steady_clock::time_point begin =
      std::chrono::steady_clock::now();
  bool solved = solvePuzzle(please_solve, solved_puzzle);
  std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
  std::cout << "SOLVED" << std::endl;
  prettyPrint(solved_puzzle);
  std::cout << solved << std::endl;

  int seconds =
      std::chrono::duration_cast<std::chrono::seconds>(end - begin).count();
  int milliseconds =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - begin)
          .count() %
      1000;
  std::cout << "Elapsed Time = " << seconds << "." << milliseconds << "[s]"
            << std::endl;
  return 0;
}