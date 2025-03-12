#include <numeric>
#include <iostream>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int max_val = max(a, max(b, c));
  int min_val = min(a, min(b, c));
  int g = gcd(a, b);
  cout << min_val / g << "/" << max_val / g<< endl;
  return 0;
}