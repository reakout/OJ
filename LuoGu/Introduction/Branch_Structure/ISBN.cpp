#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
  string ISBN;
  cin >> ISBN;
  vector<int> digit;
  for (char c : ISBN) {
    if (c != '-') {
      digit.push_back(c - '0');
    }
  }
  int CheckDigit = 0;
  for (int i = 0; i < 9; i++) {
    CheckDigit += digit[i] * (i + 1);
  }
  CheckDigit = CheckDigit % 11;
  if (CheckDigit == digit[9] || (CheckDigit == 10 && digit[9] == 'X' - '0')) {
    cout << "Right" << endl;
    return 0;
  } else {
    cout << digit[0] << "-" << digit[1] << digit[2] << digit[3] << "-"
         << digit[4] << digit[5] << digit[6] << digit[7] << digit[8] << "-";
    if (CheckDigit == 10) {
      cout << "X" << endl;
    } else {
      cout << CheckDigit << endl;
    }
    return 0;
  }
}