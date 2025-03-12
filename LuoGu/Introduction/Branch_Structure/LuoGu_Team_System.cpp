#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (5 * n <= 3 * n + 11) {
    cout << "Local" << endl;
  } else {
    cout << "Luogu" << endl;
  }
  return 0;
}