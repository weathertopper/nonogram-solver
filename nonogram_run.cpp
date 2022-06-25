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

  if (argc < 2) {
    std::cout << "ERROR: Missing IN_FILE. Exiting.";
    return -1;
  }

  std::string input_file_path = argv[1];

  int col_count, row_count;
  std::vector<std::vector<int>> col_crit, row_crit;
  std::vector<std::vector<char>> puzzle, solved_puzzle;

  buildPuzzleFromFile(input_file_path, col_count, row_count, col_crit, row_crit,
                      puzzle);

  solvePuzzle(col_count, row_count, col_crit, row_crit, puzzle, solved_puzzle);

  prettyPrint(solved_puzzle);

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