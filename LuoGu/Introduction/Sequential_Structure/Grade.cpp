#include <iostream>
using namespace std;

int main() {
  int homework, quiz, exam;
  cin >> homework >> quiz >> exam;
  double finalGrade;
  finalGrade = homework * 0.2 + quiz * 0.3 + exam * 0.5;
  cout << (int)finalGrade << endl;
  return 0;
}
