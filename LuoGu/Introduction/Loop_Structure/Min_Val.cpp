#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n;
  vector<int> a;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a.push_back(x);
  }

  cout << *min_element(a.begin(), a.end()) << endl;
}