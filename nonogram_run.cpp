#include "nonogram.h"
#include <chrono>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {

  std::chrono::steady_clock::time_point begin =
      std::chrono::steady_clock::now();

  if (argc < 3) {
    std::cout << "ERROR: Missing IN_FILE and/or OUT_FILE parameters. Exiting.";
    return -1;
  }

  std::string input_file_path = argv[1];
  std::string output_file_path = argv[2];

  int col_count, row_count;
  std::vector<std::vector<int>> col_crit, row_crit;
  std::vector<std::vector<char>> puzzle, solved_puzzle;

  buildPuzzleFromFile(input_file_path, col_count, row_count, col_crit, row_crit,
                      puzzle);

  solvePuzzle(col_count, row_count, col_crit, row_crit, puzzle, solved_puzzle);

  prettyPrint(solved_puzzle);

  //   std::cout << "col_count: " << col_count << std::endl;
  //   std::cout << "row_count: " << row_count << std::endl;

  //   for (int i = 0; i < col_crit.size(); i++) {
  //     for (int j = 0; j < col_crit[i].size(); j++) {
  //       std::cout << " crit arr[" << i << "][" << j << "]=" <<
  //       col_crit[i][j];
  //     }
  //     std::cout << std::endl;
  //   }
  //   std::cout << std::endl;

  //   for (int i = 0; i < row_crit.size(); i++) {
  //     for (int j = 0; j < row_crit[i].size(); j++) {
  //       std::cout << " crit arr[" << i << "][" << j << "]=" <<
  //       row_crit[i][j];
  //     }
  //     std::cout << std::endl;
  //   }
  //   std::cout << std::endl;

  //   puzzle[1][1] = 'y';
  //   prettyPrint(puzzle);

  //   copyPuzzle(puzzle, solved_puzzle);
  //   std::cout << "copied" << std::endl;
  //   prettyPrint(puzzle);
  //   std::cout << std::endl;
  //   prettyPrint(solved_puzzle);

  //   puzzle[1][2] = 'n';
  //   std::cout << "edited" << std::endl;
  //   prettyPrint(puzzle);
  //   std::cout << std::endl;
  //   prettyPrint(solved_puzzle);

  //   std::cout << std::endl;
  //   std::vector<char> row_vals;
  //   std::cout << "print row 1" << std::endl;
  //   getRowVals(1, puzzle, row_vals);
  //   printVals(row_vals);

  //   std::cout << std::endl;
  //   std::vector<char> col_vals;
  //   std::cout << "print col 1" << std::endl;
  //   getColVals(1, puzzle, col_vals);
  //   printVals(col_vals);

  //   std::vector<int> some_col_crit = getCriteriaAtIndex(0, col_crit);
  //   std::cout << "col crit i = 0" << std::endl;
  //   for (int j = 0; j < some_col_crit.size(); j++) {
  //     std::cout << some_col_crit[j] << " ";
  //   }
  //   std::cout << std::endl;

  //   std::vector<int> some_row_crit = getCriteriaAtIndex(6, row_crit);
  //   std::cout << "row crit i = 6" << std::endl;
  //   for (int j = 0; j < some_row_crit.size(); j++) {
  //     std::cout << some_row_crit[j] << " ";
  //   }
  //   std::cout << std::endl;

  //   for (int i = 0; i < puzzle.size(); i++) {
  //     for (int j = 0; j < puzzle[i].size(); j++) {
  //       puzzle[i][j] = '#';
  //     }
  //   }

  //   puzzle[3][2] = '?';
  //   int f_col, f_row;

  //   std::tie(f_row, f_col) = findFirstUnsolvedSquare(puzzle);

  //   std::cout << "first ? at row " << f_row << " col " << f_col << std::endl;
  //   prettyPrint(puzzle);
  // here

  std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

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