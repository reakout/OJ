#include <iostream>
using namespace std;
int main() {
  int apple;
  cin >> apple;
  if (apple == 0)
    cout << "Today, I ate 0 apple." << endl;
  if (apple == 1)
    cout << "Today, I ate 1 apple." << endl;
  if (apple > 1)
    cout << "Today, I ate " << apple << " apples." << endl;

  return 0;
}