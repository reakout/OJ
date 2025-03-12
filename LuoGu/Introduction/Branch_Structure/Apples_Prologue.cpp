#include <cmath> // 修改为 <cmath>
#include <iostream>
using namespace std;

int main() {
  int m, t, s;
  cin >> m >> t >> s;
  if (t == 0) {
    cout << 0;
  } else {
    int res = m - ceil(static_cast<double>(s) / t);
    cout << (res > 0 ? res : 0) << endl;
  }
  return 0;
}