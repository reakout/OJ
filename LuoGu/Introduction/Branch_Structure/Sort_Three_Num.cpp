#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int min_val, max_val, mid_val;
  min_val = min(a, min(b, c));
  max_val = max(a, max(b, c));
  mid_val = a + b + c - min_val - max_val;
  cout << min_val << " " << mid_val << " " << max_val << endl;
  return 0;
}