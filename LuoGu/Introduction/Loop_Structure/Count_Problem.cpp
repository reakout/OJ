#include <iostream>
using namespace std;
int main() {
  int n, x, count = 0;
  cin >> n >> x;
  for (int i = 1; i <= n; i++) {
    int tmp = i;
    while (tmp != 0) {
      if (tmp % 10 == x) {
        count++;
      }
      tmp = tmp / 10;
    }
  }
  cout << count << endl;
  return 0;
}