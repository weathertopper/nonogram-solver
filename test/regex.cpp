// C++ program to demonstrate working of regex_match()
#include <iostream>
#include <regex>

using namespace std;
int main() {

  // testing for validity now

  //   string a = "??##...#?#..."; // match

  string a = "????###??#."; // no match

  vector<int> crit{2, 1, 1};
  const char unknown_char = '?';
  const char filled_char = '#';
  const char empty_char = '.';

  string filled;
  filled += filled_char;

  string empty;
  empty += empty_char;

  string unknown;
  unknown += unknown_char;

  cout << "string " << a << endl;

  string zero_plus = "(\\" + empty + "|\\" + unknown + ")*";
  string one_plus = "(\\" + empty + "|\\" + unknown + ")+";
  //   string correct_reg = "(\\.*)(#){2}(\\.)+(#){1}(\\.)+(#){1}(\\.*)";
  string hit = ("(" + filled + "|\\" + unknown + ")");

  //   cout << "correct: " << correct_reg << endl;

  string reg;
  reg = zero_plus;
  // loop
  for (int i = 0; i < crit.size(); i++) {
    reg += hit + "{" + to_string(crit[i]) + "}"; //  crit[i] +
    if (i != crit.size() - 1) {
      reg += one_plus;
    }
  }
  reg += zero_plus;
  cout << "reg: " << reg << endl;
  regex b(reg); // Geek followed by any
                // character

  // regex_match function matches string a against regex b
  if (regex_match(a, b))
    cout << "MATCH! \n";
  else
    cout << "NO MATCH!" << endl;

  // regex_match function for matching a range in string
  // against regex b
  //   if (regex_match(a.begin(), a.end(), b))
  //     cout << "String 'a' matches with regular expression "
  //             "'b' in the range from 0 to string end\n";

  return 0;
}