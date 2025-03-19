#include <iostream>
#include <string>
#include <vector>
using namespace std;
class BigInt {
private:
  vector<int> digits;

public:
  // Instructor function.
  BigInt() { digits.push_back(0); }
  BigInt(int num) {
    if (num == 0)
      digits.push_back(0);
    while (num) {
      digits.push_back(num % 10);
      num /= 10;
    }
  }
  BigInt(const string &s) {
    for (int i = s.size() - 1; i >= 0; i--)
      digits.push_back(s[i] - '0');
  }

  // Overloading operator +.
  BigInt operator+(const BigInt &b) const {
    BigInt res;
    res.digits.clear();
    int carry = 0, i = 0;
    while (i < digits.size() || i < b.digits.size() || carry) {
      int sum = carry;
      if (i < digits.size())
        sum += digits[i];
      if (i < b.digits.size())
        sum += b.digits[i];
      res.digits.push_back(sum % 10);
      carry = sum / 10;
      i++;
    }
    return res;
  }

  // Overloading operator *.
  BigInt operator*(const BigInt &b) const {
    if (b.digits.size() == 1 && b.digits[0] == 0)
      return BigInt(0);
    if (this->digits.size() == 1 && this->digits[0] == 0)
      return BigInt(0);
    BigInt res;
    res.digits.assign(digits.size() + b.digits.size(), 0);
    for (size_t i = 0; i < digits.size(); i++) {
      for (size_t j = 0; j < b.digits.size(); j++) {
        res.digits[i + j] += digits[i] * b.digits[j];
        res.digits[i + j + 1] += res.digits[i + j] / 10;
        res.digits[i + j] %= 10;
      }
    }
    // clear the leading zeros.
    while (res.digits.size() > 1 && res.digits.back() == 0)
      res.digits.pop_back();
    return res;
  }

  // Overloading operator <<.
  friend ostream &operator<<(ostream &os, const BigInt &b) {
    for (int i = b.digits.size() - 1; i >= 0; i--)
      os << b.digits[i];
    return os;
  }
};

int main() {
  int n;
  cin >> n;
  BigInt Sum;
  BigInt res(1);
  for (int i = 1; i <= n; i++) {
    BigInt temp(i);
    res = res * temp;
    Sum = Sum + res;
  }
  cout << Sum << endl;
  return 0;
}