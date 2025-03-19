#include <iostream>
using namespace std;
int main() {
  double sum = 0;
  int k, n = 1;
  cin >> k;
  while (sum <= k) {
    sum += 1.0 / n;
    n++;
  }
  cout << n - 1 << endl;
  return 0;
}