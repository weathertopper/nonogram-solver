#ifndef NONOGRAM_H
#define NONOGRAM_H

#include <string>
#include <tuple>

extern const char start_char;
extern const char end_char;
extern const char delim;

extern const char unknown_char;
extern const char filled_char;
extern const char empty_char;

std::string readFileToString(std::string file_path);

void loadCriteriaVector(std::string crit_as_string,
                        std::vector<std::vector<int>> &crit_vect);

void initializeEmptyPuzzle(int col_count, int row_count,
                           std::vector<std::vector<char>> &puzzle);

void buildPuzzleFromFile(std::string file_path, int &col_count, int &row_count,
                         std::vector<std::vector<int>> &col_crit,
                         std::vector<std::vector<int>> &row_crit,
                         std::vector<std::vector<char>> &puzzle);

void prettyPrint(std::vector<std::vector<char>> &puzzle);

void printVals(std::vector<char> &vals);

void copyPuzzle(std::vector<std::vector<char>> &original_puzzle,
                std::vector<std::vector<char>> &copy_puzzle);

void getRowVals(int row_index, std::vector<std::vector<char>> &puzzle,
                std::vector<char> &vals);

void getColVals(int col_index, std::vector<std::vector<char>> &puzzle,
                std::vector<char> &vals);

std::vector<int> getCriteriaAtIndex(int crit_index,
                                    std::vector<std::vector<int>> &crit_vect);

bool isStraightSolved(std::vector<char> &vals, std::vector<int> &crit_vect);

bool isPuzzleSolved(std::vector<std::vector<char>> &puzzle, int &col_count,
                    int &row_count, std::vector<std::vector<int>> &col_crit,
                    std::vector<std::vector<int>> &row_crit);

std::tuple<int, int>
findFirstUnsolvedSquare(std::vector<std::vector<char>> &puzzle);

// defined
//-----
// undefined

// follow sudoku format
void solvePuzzle(std::vector<std::vector<int>> &col_crit,
                 std::vector<std::vector<int>> &row_crit,
                 std::vector<std::vector<char>> &puzzle,
                 std::vector<std::vector<char>> &solved_puzzle);

// hard part
bool isStraightValid(std::vector<char> &vals, std::vector<int> &crit_vect);

#endif