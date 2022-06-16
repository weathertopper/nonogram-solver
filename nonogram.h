#ifndef NONOGRAM_H
#define NONOGRAM_H

#include <string>

void stringToCriteriaArray(std::string crit_as_string, int **criteria);

void buildPuzzleFromFile(std::string file_path, int *col_count, int *row_count,
                         int **col_criteria, int **row_criteria,
                         char *empty_puzzle);

void solvePuzzle(std::string input_file_path, std::string output_file_path);

void getRowVals(char *puzzle, int row_number, char *row_vals);

void getColVals(char *puzzle, int col_number, char *col_vals);

int *getCriteria(int *criteria_arr, int position);

bool isSubsectionValid(char *subsection);

bool isPuzzleValid(char *puzzle);

void copyPuzzle(char *original_puzzle, char *copy_puzzle);

int findFirstUnsolvedSquare(char *puzzle);

void prettyPrint(char *puzzle);

#endif