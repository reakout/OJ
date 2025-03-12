#include <iostream>
using namespace std;
int main() {
  int x, n;
  cin >> x >> n;
  int total_days = n/7*5,remain_days=n%7;
  for (int i = 0;i<remain_days;i++) {
    if (x+i == 6 || x+i == 7) {
      continue;
    }
    total_days++;
  }
  cout << total_days*250 << endl;
  return 0;
}