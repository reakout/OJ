#include <iomanip>
#include <iostream>
using namespace std;
int main() {
  int unit;
  double price = 0.0;
  cin >> unit;
  if (unit <= 150) {
    price = unit * 0.4463;
  } else if (unit <= 400) {
    price = 150 * 0.4463 + (unit - 150) * 0.4663;
  } else {
    price = 150 * 0.4463 + 250 * 0.4663 + (unit - 400) * 0.5663;
  }
  cout << fixed << setprecision(1) << price << endl;
  return 0;
}