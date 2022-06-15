#include "nonogram.h"
#include <chrono>
#include <iostream>

int main() {
  std::chrono::steady_clock::time_point begin =
      std::chrono::steady_clock::now();
  bool solved = true; // solvePuzzle(please_solve, solved_puzzle);
  std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
  std::cout << solved << std::endl;

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