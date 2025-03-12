#include <climits>
#include <cmath>
#include <iostream>
using namespace std;
int main() {
  int total_num, total_price = INT_MAX, size, price;
  cin >> total_num;
  for (int i = 0; i < 3; i++) {
    cin >> size >> price;
    price = price * ((total_num + size - 1) / size);
    if (total_price > price) {
      total_price = price;
    }
  }
  cout << total_price << endl;
  return 0;
}