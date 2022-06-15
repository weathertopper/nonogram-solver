#include "sudoku.h"
#include <gtest/gtest.h>
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

TEST(SudokuSuite, singePuzzle) {
  int result_puzzle[81];
  solvePuzzle(UNSOLVED_PUZZLE, result_puzzle);
  for (int i = 0; i < 81; ++i) {
    EXPECT_EQ(result_puzzle[i], SOLVED_PUZZLE[i]) << "at index <" << i << ">";
  }
}
