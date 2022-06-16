#include "nonogram.h"
#include <chrono>
#include <fstream>
#include <iostream>
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

  solvePuzzle(input_file_path, output_file_path);

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