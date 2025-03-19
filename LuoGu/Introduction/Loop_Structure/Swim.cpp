#include <iostream>
using namespace std;
int main() {
  int n;
  double s, sum = 0, step = 2;
  cin >> s;
  for (n = 0; sum < s; n++) {
    sum += step;
    step *= 0.98;
  }
  cout << n << endl;
}