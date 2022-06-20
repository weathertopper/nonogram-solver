#ifndef NONOGRAM_H
#define NONOGRAM_H

#include <string>

extern const char start_char;
extern const char end_char;
extern const char delim;

extern const char unknown_char;
extern const char filled_char;
extern const char empty_char;

std::string readFileToString(std::string file_path);

void loadCriteriaArray(std::string crit_as_string,
                       std::vector<std::vector<int>> &crit_vect);

void initializeEmptyPuzzle(int col_count, int row_count,
                           std::vector<std::vector<char>> &puzzle);

void buildPuzzleFromFile(std::string file_path, int &col_count, int &row_count,
                         std::vector<std::vector<int>> &col_crit,
                         std::vector<std::vector<int>> &row_crit,
                         std::vector<std::vector<char>> &puzzle);

void prettyPrint(std::vector<std::vector<char>> &puzzle);

int getCount(std::string file_path, int file_row);

void getRowVals(char *puzzle, int row_number, char *row_vals);

void getColVals(char *puzzle, int col_number, char *col_vals);

int *getCriteria(int *criteria_arr, int position);

bool isSubsectionValid(char *subsection);

bool isPuzzleValid(char *puzzle);

void copyPuzzle(char *original_puzzle, char *copy_puzzle);

int findFirstUnsolvedSquare(char *puzzle);

#endif