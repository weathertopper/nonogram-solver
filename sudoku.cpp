#include "sudoku.h"
#include <iostream>
#include <string>

const int box_start_indices[9] = {0, 3, 6, 27, 30, 33, 54, 57, 60};

void getRowVals(int *puzzle, int row_number, int *row_vals) {
  int row_indices[9];
  int row_ii = 0;
  for (int i = row_number * 9; i < (row_number * 9) + 9; ++i) {
    row_indices[row_ii++] = i;
  }
  for (int i = 0; i < 9; ++i) {
    row_vals[i] = puzzle[row_indices[i]];
  }
}

void getColVals(int *puzzle, int col_number, int *col_vals) {
  int col_indices[9];
  int col_ii = 0;
  for (int i = col_number; i < 81; i += 9) {
    col_indices[col_ii++] = i;
  }
  for (int i = 0; i < 9; ++i) {
    col_vals[i] = puzzle[col_indices[i]];
  }
}

void getBoxVals(int *puzzle, int box_number, int *box_vals) {
  int box_indices[9];
  int box_ii = 0;
  int shift_index = box_start_indices[box_number];
  for (int s = 0; s < 3; s++) {
    for (int i = shift_index; i < shift_index + 3; ++i) {
      box_indices[box_ii++] = i;
    }
    shift_index += 9;
  }
  for (int i = 0; i < 9; ++i) {
    box_vals[i] = puzzle[box_indices[i]];
  }
}

void printSubsection(int *subsection) {
  for (int i = 0; i < 9; ++i) {
    std::cout << subsection[i] << " ";
  }
  std::cout << std::endl;
}

bool isSubsectionValid(int *subsection) {
  int zero_to_nine[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  for (int i = 0; i < 9; ++i) {
    int sub_val = subsection[i];
    if (sub_val == 0) {
      continue;
    }
    if (zero_to_nine[sub_val] == 0) {
      return false;
    }
    zero_to_nine[sub_val] = 0;
  }
  return true;
}

bool isPuzzleValid(int *puzzle) {
  int zero_to_eight[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  for (int i = 0; i < 9; ++i) {
    int row_vals[9];
    getRowVals(puzzle, i, row_vals);
    if (!isSubsectionValid(row_vals)) {
      return false;
    }
    int col_vals[9];
    getColVals(puzzle, i, col_vals);
    if (!isSubsectionValid(col_vals)) {
      return false;
    }
    int box_vals[9];
    getBoxVals(puzzle, i, box_vals);
    if (!isSubsectionValid(box_vals)) {
      return false;
    }
  }
  return true;
}

void copyPuzzle(int *original_puzzle, int *copy_puzzle) {
  for (int i = 0; i < 81; ++i) {
    copy_puzzle[i] = original_puzzle[i];
  }
}

int findFirstZero(int *puzzle) {
  for (int i = 0; i < 81; ++i) {
    if (puzzle[i] == 0) {
      return i;
    }
  }
  return -1;
}

bool solvePuzzle(int *puzzle, int *solved_puzzle) {
  if (findFirstZero(puzzle) == -1) {
    copyPuzzle(puzzle, solved_puzzle);
    return true;
  }
  for (int i = 1; i < 10; ++i) {
    int copy[81];
    copyPuzzle(puzzle, copy);
    int first_zero = findFirstZero(copy);
    copy[first_zero] = i;
    if (!isPuzzleValid(copy)) {
      continue;
    }
    bool solved = solvePuzzle(copy, solved_puzzle);
    if (!solved) {
      continue;
    }
    return true;
  }
  return false;
}

void prettyPrint(int *puzzle) {
  std::string pretty = "";
  for (int i = 0; i < 81; ++i) {
    pretty += std::to_string(puzzle[i]);
    if ((i + 1) % 3 == 0) {
      pretty += "  ";
    }
    if ((i + 1) % 9 == 0) {
      pretty += "\n";
    }
    if ((i + 1) % 27 == 0) {
      pretty += "\n";
    }
  }
  std::cout << pretty << std::endl;
}