#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int problem_choose;
  cin >> problem_choose;
  if (problem_choose == 1) {
    cout << "I love Luogu!" << endl;
  } else if (problem_choose == 2) {
    cout << 2 + 4 << " " << 10 - 2 - 4 << endl;
  } else if (problem_choose == 3) {
    cout << 14 / 4 << endl;
    cout << 14 - 14 % 4 << endl;
    cout << 14 % 4 << endl;
  } else if (problem_choose == 4) {
    cout << 500 * 1.0 / 3 << endl;
  } else if (problem_choose == 5) {
    cout << (260 + 220) / (12 + 20) << endl;
  } else if (problem_choose == 6) {
    cout << pow(36 + 81, 0.5) << endl;
  } else if (problem_choose == 7) {
    cout << 110 << endl;
    cout << 90 << endl;
    cout << 0 << endl;
  } else if (problem_choose == 8) {
    double pi = 3.141593;
    int r = 5;
    cout << 2 * pi * r << endl;
    cout << pi * r * r << endl;
    cout << 4.0 / 3 * pi * r * r * r << endl;
  } else if (problem_choose == 9) {
    cout << (((1 + 1) * 2 + 1) * 2 + 1) * 2 << endl;
  } else if (problem_choose == 10) {
    cout << 9 << endl;
  } else if (problem_choose == 11) {
    cout << 100.0 / 3 << endl;
  } else if (problem_choose == 12) {
    cout << 'M' - 'A' + 1 << endl;
    cout << char('A' + 17) << endl;
  } else if (problem_choose == 13) {
    double pi = 3.141593;
    int r1 = 4, r2 = 10;
    double v = 4.0 / 3 * pi * r2 * r2 * r2 - 4.0 / 3 * pi * r1 * r1 * r1;
    cout << round(pow(v, 1.0 / 3)) << endl;
  } else if (problem_choose == 14) {
    cout << 50 << endl;
  }
  return 0;
}