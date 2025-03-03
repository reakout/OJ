#include <iostream>
using namespace std;

int main() {
  int A, B, C, K, res;
  cin >> A >> B >> C >> K;
  if (K <= A + B)
    res = min(A, K);
  else
    res = A - (K - A - B);
  cout << res << endl;
  return 0;
}