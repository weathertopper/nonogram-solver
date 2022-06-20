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

  std::cout << "col_count: " << col_count << std::endl;
  std::cout << "row_count: " << row_count << std::endl;

  for (int i = 0; i < col_crit.size(); i++) {
    for (int j = 0; j < col_crit[i].size(); j++) {
      std::cout << " crit arr[" << i << "][" << j << "]=" << col_crit[i][j];
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

  for (int i = 0; i < row_crit.size(); i++) {
    for (int j = 0; j < row_crit[i].size(); j++) {
      std::cout << " crit arr[" << i << "][" << j << "]=" << row_crit[i][j];
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

  puzzle[1][1] = 'y';
  std::cout << "start" << std::endl;
  prettyPrint(puzzle);

  copyPuzzle(puzzle, solved_puzzle);
  std::cout << "copied" << std::endl;
  prettyPrint(puzzle);
  std::cout << std::endl;
  prettyPrint(solved_puzzle);

  puzzle[2][2] = 'n';
  std::cout << "edited" << std::endl;
  prettyPrint(puzzle);
  std::cout << std::endl;
  prettyPrint(solved_puzzle);

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