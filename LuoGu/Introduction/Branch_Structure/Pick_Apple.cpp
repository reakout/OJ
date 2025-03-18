#include <iostream>
using namespace std;
int main() {
  int apple_height[10], count = 0, m_height;
  for (int i = 0; i < 10; i++) {
    cin >> apple_height[i];
  }
  cin >> m_height;
  m_height += 30;
  for (int i = 0; i < 10; i++) {
    if (apple_height[i] <= m_height) {
      count++;
    }
  }
  cout << count << endl;
  return 0;
}