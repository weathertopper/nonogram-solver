#ifndef SUDOKU_H
#define SUDOKU_H

extern const int box_start_indices[9];

void getRowVals(int *puzzle, int row_number, int *row_vals);

void getColVals(int *puzzle, int col_number, int *col_vals);

void getBoxVals(int *puzzle, int box_number, int *box_vals);

void printSubsection(int *subsection);

bool isSubsectionValid(int *subsection);

bool isPuzzleValid(int *puzzle);

void copyPuzzle(int *original_puzzle, int *copy_puzzle);

int findFirstZero(int *puzzle);

bool solvePuzzle(int *puzzle, int *solved_puzzle);

void prettyPrint(int *puzzle);

#endif