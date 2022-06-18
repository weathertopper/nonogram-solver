#include "nonogram.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

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

void stringToCriteriaArray(std::string crit_as_string, int **criteria) {}

// void buildPuzzleFromFile(std::string file_path, int *col_count, int
// *row_count,
//                          int ***col_criteria, int ***row_criteria,
//                          char *empty_puzzle) {
//   //   //   int i = 8;
//   //   int count = 123;
//   //   *col_count = count;
//   //   row_count = &count;
//   std::ifstream input_file(file_path); // open the file
//   if (input_file.is_open() && input_file.good()) {
//     std::string line;
//     for (int line_num = 0; getline(input_file, line) && line_num < 4;
//          line_num++) {
//       switch (line_num) {
//       case 0:
//         *col_count = std::stoi(line);
//         break;
//       case 1:
//         *row_count = std::stoi(line);
//         break;
//       case 2: {
//         // do something special here
//         std::cout << "col_crit" << std::endl;
//         std::cout << *col_count << std::endl;
//         int max_crit_len = std::ceil((*col_count * 1.0) / 2);
//         std::cout << "max: " << max_crit_len << std::endl;
//         col_criteria = new int **[*col_count];
//         for (int i = 0; i < *col_count; i++) {
//           col_criteria[i] = new int *[max_crit_len];
//         }
//         for (int i = 0; i < *col_count; i++) {
//           for (int j = 0; j < max_crit_len; j++) {
//             int val = i + j;
//             col_criteria[i][j] = val;
//           }
//         }
//         break;
//       }
//       case 3: {
//         // do same something special here
//         std::cout << "row_crit" << std::endl;
//         break;
//       }
//       }
//     }
//     input_file.close();
//     int max_crit_len = std::ceil((*col_count * 1.0) / 2);
//     for (int i = 0; i < *col_count; i++) {
//       for (int j = 0; j < max_crit_len; j++) {
//         std::cout << "col_criteria[" << i << "][" << j << "]=" << std::endl;
//         std::cout << *col_criteria << std::endl;
//         std::cout << *col_criteria[i] << std::endl;
//         std::cout << *col_criteria[i][j] << std::endl;
//       }
//     }

//   } else {
//     std::cout << "ERROR: Failed to open file.";
//   }
// }

// int getCount(std::string file_path, int file_row) {}

void solvePuzzle(std::string file_str, std::string output_file_path) {
  std::cout << "INPUT FILE STR:\n" << file_str << std::endl;
  std::cout << "OUTPUT FILE: " << output_file_path << std::endl;
  int col_count, row_count;
  int **col_criteria, **row_criteria;
  char empty_puzzle;
  //   buildPuzzleFromFile(input_file_path, &col_count, &row_count,
  //   &col_criteria,
  //                       &row_criteria, &empty_puzzle);
  std::cout << "col_count: " << col_count << std::endl;
  std::cout << "row_count: " << row_count << std::endl;
  int max_crit_len = std::ceil((col_count * 1.0) / 2);
  std::cout << "max_crit_len: " << max_crit_len << std::endl;
  for (int i = 0; i < col_count; i++) {
    for (int j = 0; j < max_crit_len; j++) {
      std::cout << "col_criteria[" << i << "][" << j << "]=" << std::endl;
      std::cout << col_criteria << std::endl;
      std::cout << col_criteria[i] << std::endl;
      std::cout << col_criteria[i][j] << std::endl;
    }
  }

  std::cout << "col_criteria: " << col_criteria << std::endl;
  std::cout << "row_criteria: " << row_criteria << std::endl;
  std::cout << "empty_puzzle: " << empty_puzzle << std::endl;
}

void getRowVals(char *puzzle, int row_number, char *row_vals) {}

void getColVals(char *puzzle, int col_number, char *col_vals) {}

int *getCriteria(int *criteria_arr, int position) {
  int *i;
  return i;
}

bool isSubsectionValid(char *subsection) { return true; }

bool isPuzzleValid(char *puzzle) { return true; }

void copyPuzzle(char *original_puzzle, char *copy_puzzle) {}

int findFirstUnsolvedSquare(char *puzzle) { return 0; }

void prettyPrint(char *puzzle) {}

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