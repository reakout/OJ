#include <cmath>
#include <iostream>
using namespace std;
int main() {
  int k, coins = 0;
  cin >> k;
  int m = (sqrt(8 * k + 1) - 1) / 2;
  coins += m * (m + 1) * (2 * m + 1) / 6;
  int remaining = k - m * (m + 1) / 2;
  coins += (m + 1) * remaining;
  cout << coins << endl;
  return 0;
}