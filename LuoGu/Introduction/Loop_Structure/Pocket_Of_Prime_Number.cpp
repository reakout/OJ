#include <iostream>
#include <vector>
using namespace std;
bool isPrime(int n) {
  if (n < 2)
    return false;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0)
      return false;
  }
  return true;
}
int main() {
  int l, sum = 0;
  vector<int> prime;
  cin >> l;
  for (int i = 0; sum <= l - i; i++) {
    if (isPrime(i)) {
      sum += i;
      prime.push_back(i);
    }
  }
  for (auto i : prime) {
    cout << i << endl;
  }
  cout << prime.size() << endl;
  return 0;
}