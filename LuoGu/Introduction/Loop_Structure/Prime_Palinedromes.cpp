#include <iostream>
#include <string>
using namespace std;
bool isPalindrome(int n) {
  string s = to_string(n);
  int i = 0, j = s.size() - 1;
  while (i < j) {
    if (s[i] != s[j])
      return false;
    i++;
    j--;
  }
  return true;
}
bool isPrime(int n) {
  if (n <= 1)
    return false;
  if (n <= 3)
    return true;
  if (n % 2 == 0 || n % 3 == 0)
    return false;
  for (int i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0)
      return false;
  }
  return true;
}

int main() {
  int a, b;
  cin >> a >> b;
  if (b>=100000000)
    b = 9999999;
  for (int i = a; i <= b; i++) {
    if (isPalindrome(i) && isPrime(i))
      cout << i << endl;
  }
  return 0;
}