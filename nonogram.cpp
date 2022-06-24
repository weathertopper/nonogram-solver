#include "nonogram.h"
#include <chrono>
#include <cmath>
#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

const char start_char = '{';
const char end_char = '}';
const char delim = ',';

const char unknown_char = '?';
const char filled_char = '#';
const char empty_char = '.';

// possible improvement-- flatten puzzle to 1-D vector to see if that improves
// timing

std::string readFileToString(std::string file_path) {
  std::ifstream input_file(file_path);
  std::string line_str;
  std::string file_str;
  while (std::getline(input_file, line_str)) {
    file_str += line_str;
    file_str.push_back('\n');
  }
  input_file.close();
  return file_str;
}

void loadCriteriaVector(std::string crit_as_string,
                        std::vector<std::vector<int>> &crit_vect) {

  std::string possible_int = "";
  std::string loop_string =
      crit_as_string.substr(1, crit_as_string.length() - 2);

  int crit_index = -1;
  for (int s = 0; s < loop_string.length(); s++) {
    char curr_char = loop_string[s];
    if (curr_char == start_char) {
      crit_index += 1;
      crit_vect.push_back(std::vector<int>());
    } else if (curr_char == end_char || curr_char == delim) {
      if (!possible_int.empty()) {
        crit_vect[crit_index].push_back(std::stoi(possible_int));
        possible_int = "";
      }
    } else {
      possible_int.push_back(curr_char);
    }
  }
}

void initializeEmptyPuzzle(int col_count, int row_count,
                           std::vector<std::vector<char>> &puzzle) {
  for (int i = 0; i < row_count; i++) {
    puzzle.push_back(std::vector<char>());
    for (int j = 0; j < col_count; j++) {
      puzzle[i].push_back(unknown_char);
    }
  }
}

void buildPuzzleFromFile(std::string input_file_path, int &col_count,
                         int &row_count,
                         std::vector<std::vector<int>> &col_crit,
                         std::vector<std::vector<int>> &row_crit,
                         std::vector<std::vector<char>> &puzzle) {

  std::string file_str = readFileToString(input_file_path);

  std::istringstream iss(file_str);

  std::string count_str;

  std::getline(iss, count_str);
  col_count = std::stoi(count_str);

  std::getline(iss, count_str);
  row_count = std::stoi(count_str);

  std::string col_crit_str;
  std::getline(iss, col_crit_str);

  std::string row_crit_str;
  std::getline(iss, row_crit_str);

  loadCriteriaVector(col_crit_str, col_crit);
  loadCriteriaVector(row_crit_str, row_crit);
  initializeEmptyPuzzle(
      col_count, row_count,
      puzzle); // improvement, init empty or partially-complete puzzle
}

void prettyPrint(std::vector<std::vector<char>> &puzzle) {
  for (int i = 0; i < puzzle.size(); i++) {
    for (int j = 0; j < puzzle[i].size(); j++) {
      std::cout << puzzle[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void printVals(std::vector<char> &vals) {
  for (int i = 0; i < vals.size(); i++) {
    std::cout << vals[i] << " ";
  }
  std::cout << std::endl;
}

void copyPuzzle(std::vector<std::vector<char>> &original_puzzle,
                std::vector<std::vector<char>> &copy_puzzle) {
  for (int i = 0; i < original_puzzle.size(); i++) {
    copy_puzzle.push_back(std::vector<char>());
    for (int j = 0; j < original_puzzle[i].size(); j++) {
      copy_puzzle[i].push_back(original_puzzle[i][j]);
    }
  }
}

// assumes rectangular puzzle
void getRowVals(int row_index, std::vector<std::vector<char>> &puzzle,
                std::vector<char> &vals) {
  int col_count = puzzle[0].size();
  for (int j = 0; j < col_count; j++) {
    vals.push_back(puzzle[row_index][j]);
  }
}

void getColVals(int col_index, std::vector<std::vector<char>> &puzzle,
                std::vector<char> &vals) {
  int row_count = puzzle.size();
  for (int i = 0; i < row_count; i++) {
    vals.push_back(puzzle[i][col_index]);
  }
}

std::vector<int> getCriteriaAtIndex(int crit_index,
                                    std::vector<std::vector<int>> &crit_vect) {
  return crit_vect[crit_index];
}

bool isStraightSolved(std::vector<char> &vals, std::vector<int> &crit_vect) {

  std::string val_string(vals.begin(), vals.end());

  std::string filled;
  filled += filled_char;

  std::string empty;
  empty += empty_char;

  std::string zero_plus = "(\\" + empty + "*)";
  std::string one_plus = "(\\" + empty + ")+";
  std::string hit = ("(" + filled + ")");

  std::string reg;
  reg = zero_plus;
  for (int i = 0; i < crit_vect.size(); i++) {
    reg += hit + "{" + std::to_string(crit_vect[i]) + "}";
    if (i != crit_vect.size() - 1) {
      reg += one_plus;
    }
  }
  reg += zero_plus;
  std::regex expected_val_string(reg);

  return regex_match(val_string, expected_val_string);
}

bool isPuzzleSolved(std::vector<std::vector<char>> &puzzle, int col_count,
                    int row_count, std::vector<std::vector<int>> &col_crit,
                    std::vector<std::vector<int>> &row_crit) {
  for (int i = 0; i < row_count; i++) {
    std::vector<char> row_vals;
    getRowVals(i, puzzle, row_vals);
    std::vector<int> crit_vect = getCriteriaAtIndex(6, row_crit);
    if (!isStraightSolved(row_vals, crit_vect)) {
      return false;
    }
  }
  for (int i = 0; i < col_count; i++) {
    std::vector<char> col_vals;
    getColVals(i, puzzle, col_vals);
    std::vector<int> crit_vect = getCriteriaAtIndex(6, col_crit);
    if (!isStraightSolved(col_vals, crit_vect)) {
      return false;
    }
  }
  return true;
}

// ---

void solvePuzzle(std::string file_str, std::string output_file_path) {}

bool isStraightValid(char *subsection) { return true; }

// return either tuple or pass in col, row to set and return void
int findFirstQuestionableSquare(char *puzzle) { return 0; }

// bool isSubsectionValid(int *subsection) {
//   int zero_to_nine[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//   for (int i = 0; i < 9; ++i) {
//     int sub_val = subsection[i];
//     if (sub_val == 0) {
//       continue;
//     }
//     if (zero_to_nine[sub_val] == 0) {
//       return false;
//     }
//     zero_to_nine[sub_val] = 0;
//   }
//   return true;
// }

// bool isPuzzleValid(int *puzzle) {
//   int zero_to_eight[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
//   for (int i = 0; i < 9; ++i) {
//     int row_vals[9];
//     getRowVals(puzzle, i, row_vals);
//     if (!isSubsectionValid(row_vals)) {
//       return false;
//     }
//     int col_vals[9];
//     getColVals(puzzle, i, col_vals);
//     if (!isSubsectionValid(col_vals)) {
//       return false;
//     }
//     int box_vals[9];
//     getBoxVals(puzzle, i, box_vals);
//     if (!isSubsectionValid(box_vals)) {
//       return false;
//     }
//   }
//   return true;
// }

// int findFirstZero(int *puzzle) {
//   for (int i = 0; i < 81; ++i) {
//     if (puzzle[i] == 0) {
//       return i;
//     }
//   }
//   return -1;
// }

// bool solvePuzzle(std::string file_path) {
//   std::cout << file_path << std::endl;
//   return true;
//   //   if (findFirstZero(puzzle) == -1) {
//   //     copyPuzzle(puzzle, solved_puzzle);
//   //     return true;
//   //   }
//   //   for (int i = 1; i < 10; ++i) {
//   //     int copy[81];
//   //     copyPuzzle(puzzle, copy);
//   //     int first_zero = findFirstZero(copy);
//   //     copy[first_zero] = i;
//   //     if (!isPuzzleValid(copy)) {
//   //       continue;
//   //     }
//   //     bool solved = solvePuzzle(copy, solved_puzzle);
//   //     if (!solved) {
//   //       continue;
//   //     }
//   //     return true;
//   //   }
//   //   return false;
// }