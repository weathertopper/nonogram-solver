#include "nonogram.h"
#include <chrono>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char *argv[]) {

  std::chrono::steady_clock::time_point begin =
      std::chrono::steady_clock::now();

  if (argc < 3) {
    std::cout << "ERROR: Missing IN_FILE and/or OUT_FILE parameters. Exiting.";
    return -1;
  }

  std::string input_file_path = argv[1];
  std::string output_file_path = argv[2];

  std::string file_str = readFileToString(input_file_path);

  std::istringstream iss(file_str);
  std::string count_str;
  std::getline(iss, count_str);
  int col_count = std::stoi(count_str);
  std::getline(iss, count_str);
  int row_count = std::stoi(count_str);
  std::string col_crit_str;
  std::getline(iss, col_crit_str);
  std::string row_crit_str;
  std::getline(iss, row_crit_str);

  std::cout << "col_count: " << col_count << std::endl;
  std::cout << "row_count: " << row_count << std::endl;
//   int max_crit_len = std::ceil((col_count * 1.0) / 2);
//   std::cout << "max_crit_len: " << max_crit_len << std::endl;
  std::cout << "col_crit_str: " << col_crit_str << std::endl;
  std::cout << "row_crit_str: " << row_crit_str << std::endl;
  //   std::cout << "empty_puzzle: " << empty_puzzle << std::endl;

  //   solvePuzzle(file_str, output_file_path);

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