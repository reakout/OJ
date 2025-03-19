#include <iostream>
using namespace std;
int main() {
  int side, count = 1;
  cin >> side;
  for (int i = 0; i < side; i++) {
    for (int j = side; j > i; j--) {
      if (count < 10)
        cout << 0 << count;
      else
        cout << count;
      count++;
    }
    cout << endl;
  }
  return 0;
}