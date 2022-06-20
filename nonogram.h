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

void solvePuzzle(std::vector<std::vector<int>> &col_crit,
                 std::vector<std::vector<int>> &row_crit,
                 std::vector<std::vector<char>> &puzzle,
                 std::vector<std::vector<char>> &solved_puzzle);

void prettyPrint(std::vector<std::vector<char>> &puzzle);

void printVals(std::vector<char> &vals);

int getCount(std::string file_path, int file_row);

void getRowVals(int row_index, std::vector<std::vector<char>> &puzzle,
                std::vector<char> &vals);

void getColVals(int col_index, std::vector<std::vector<char>> &puzzle,
                std::vector<char> &vals);

// should work for row or col criteria
std::vector<int> getCriteria(int crit_index,
                             std::vector<std::vector<int>> &crit_vect);

bool isSubsectionValid(char *subsection);

bool isPuzzleValid(char *puzzle);

void copyPuzzle(std::vector<std::vector<char>> &original_puzzle,
                std::vector<std::vector<char>> &copy_puzzle);

int findFirstUnsolvedSquare(char *puzzle);

#endif