#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  int num[3], index[3];
  for (int i = 0; i < 3; i++) {
    cin >> num[i];
  }
  for (int i = 0; i < 3; i++) {
    char idx;
    cin >> idx;
    index[i] = idx - 'A';
  }
  sort(num, num + 3);
  cout << num[index[0]] << " " << num[index[1]] << " " << num[index[2]] << endl;
  return 0;
}