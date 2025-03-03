#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  double a, b, c, p, s;
  cin >> a >> b >> c;
  p = (a + b + c) / 2;
  s = sqrt(p * (p - a) * (p - b) * (p - c));
  cout << fixed << setprecision(1) << s << endl;
  return 0;
}
