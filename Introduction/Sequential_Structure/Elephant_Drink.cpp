#include <iostream>
using namespace std;

int main() {
  int r, h;
  cin >> h >> r;
  float v = 3.14 * r * r * h;
  cout << (int)(20000.0 / v) + 1 << endl;
}
