#include <iostream>
using namespace std;
int main() {
  int length, days=1;
  cin >> length;
  while (length != 1) {
    days++;
    length /= 2;
  }
  cout << days << endl;
}