#include <iostream>
using namespace std;

int main() {
  int input;
  cin >> input;
  bool special1, special2;
  special1 = input % 2 == 0;
  special2 = input > 4 && input <= 12;
  cout << (special1 && special2) << " " << (special1 || special2) << " "
       << ((!special1 && special2) || (special1 && !special2)) << " "
       << (!special1 && !special2) << endl;
  return 0;
}