#include "nonogram.h"
#include <chrono>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

const char start_char = '{';
const char end_char = '}';
const char delim = ',';

const char unknown_char = '?';
const char filled_char = '#';
const char empty_char = ' ';

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

void loadCriteriaArray(std::string crit_as_string,
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
  for (int i = 0; i < col_count; i++) {
    puzzle.push_back(std::vector<char>());
    for (int j = 0; j < row_count; j++) {
      puzzle[i].push_back(unknown_char);
    }
  }
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

  loadCriteriaArray(col_crit_str, col_crit);
  loadCriteriaArray(row_crit_str, row_crit);
  initializeEmptyPuzzle(col_count, row_count, puzzle);
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

void solvePuzzle(std::string file_str, std::string output_file_path) {}

int *getCriteria(int *criteria_arr, int position) {
  int *i;
  return i;
}

bool isSubsectionValid(char *subsection) { return true; }

bool isPuzzleValid(char *puzzle) { return true; }

int findFirstUnsolvedSquare(char *puzzle) { return 0; }

// const int box_start_indices[9] = {0, 3, 6, 27, 30, 33, 54, 57, 60};

// void getRowVals(int *puzzle, int row_number, int *row_vals) {
//   int row_indices[9];
//   int row_ii = 0;
//   for (int i = row_number * 9; i < (row_number * 9) + 9; ++i) {
//     row_indices[row_ii++] = i;
//   }
//   for (int i = 0; i < 9; ++i) {
//     row_vals[i] = puzzle[row_indices[i]];
//   }
// }

// void getColVals(int *puzzle, int col_number, int *col_vals) {
//   int col_indices[9];
//   int col_ii = 0;
//   for (int i = col_number; i < 81; i += 9) {
//     col_indices[col_ii++] = i;
//   }
//   for (int i = 0; i < 9; ++i) {
//     col_vals[i] = puzzle[col_indices[i]];
//   }
// }

// void getBoxVals(int *puzzle, int box_number, int *box_vals) {
//   int box_indices[9];
//   int box_ii = 0;
//   int shift_index = box_start_indices[box_number];
//   for (int s = 0; s < 3; s++) {
//     for (int i = shift_index; i < shift_index + 3; ++i) {
//       box_indices[box_ii++] = i;
//     }
//     shift_index += 9;
//   }
//   for (int i = 0; i < 9; ++i) {
//     box_vals[i] = puzzle[box_indices[i]];
//   }
// }

// void printSubsection(int *subsection) {
//   for (int i = 0; i < 9; ++i) {
//     std::cout << subsection[i] << " ";
//   }
//   std::cout << std::endl;
// }

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

// void copyPuzzle(int *original_puzzle, int *copy_puzzle) {
//   for (int i = 0; i < 81; ++i) {
//     copy_puzzle[i] = original_puzzle[i];
//   }
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

// void prettyPrint(int *puzzle) {
//   std::string pretty = "";
//   for (int i = 0; i < 81; ++i) {
//     pretty += std::to_string(puzzle[i]);
//     if ((i + 1) % 3 == 0) {
//       pretty += "  ";
//     }
//     if ((i + 1) % 9 == 0) {
//       pretty += "\n";
//     }
//     if ((i + 1) % 27 == 0) {
//       pretty += "\n";
//     }
//   }
//   std::cout << pretty << std::endl;
// }