#include <iostream>
#include <stack>
using namespace std;
int main() {
  char c;
  stack<char> s;
  while (cin.get(c) && c != '\n') {
    if (c == '-') {
      cout << "-";
      continue;
    }
    s.push(c);
  }
  if (s.size() == 1 && s.top() == '0') {
    cout << "0";
    return 0;
  }
  while (!s.empty() && s.top() == '0') {
    s.pop();
  }
  while (!s.empty()) {
    cout << s.top();
    s.pop();
  }
  cout << endl;
  return 0;
}