#include <iomanip>
#include <ios>
#include <iostream>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int avg1 = 0, avg1_num = 0, avg2 = 0, avg2_num = 0;
  for (int i = 1; i <= n; i++) {
    if (i % k == 0) {
      avg1 += i;
      avg1_num++;
    } else {
      avg2 += i;
      avg2_num++;
    }
  }
  cout << fixed << setprecision(1) << static_cast<float>(avg1) / avg1_num << " "
       << static_cast<float>(avg2) / avg2_num << endl;
}