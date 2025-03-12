#include <iostream>
using namespace std;
int main() {
  int school, home, max = 8, res = 0;
  for (int i = 0; i < 7; i++) {
    cin >> school >> home;
    if (school + home > max) {
      max = school + home;
      res = i + 1;
    }
  }
  cout << res << endl;
  return 0;
}