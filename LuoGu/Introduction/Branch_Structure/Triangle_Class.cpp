#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a + b <= c || a + c <= b || b + c <= a) {
    cout << "Not triangle" << endl;
    return 0;
  }
  int max_val = max(a, max(b, c));
  if (a * a + b * b + c * c == 2 * max_val * max_val) {
    cout << "Right triangle" << endl;
  }
  if (a * a + b * b + c * c > 2 * max_val * max_val) {
    cout << "Acute triangle" << endl;
  }
  if (a * a + b * b + c * c < 2 * max_val * max_val) {
    cout << "Obtuse triangle" << endl;
  }
  if (a == b || b == c || a == c) {
    cout << "Isosceles triangle" << endl;
  }
  if (a == b && b == c) {
    cout << "Equilateral triangle" << endl;
  }
  return 0;
}