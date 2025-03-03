#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  long long res;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  res = a[0];
  for (int i = 1; i < n; i++) {
    if (a[i] > a[i - 1]) res += a[i] - a[i - 1];
  }
  cout << res << endl;
  return 0;
}
