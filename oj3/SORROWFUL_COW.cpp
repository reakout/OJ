#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int board_num, cow_num, stall_num;
  cin >> board_num >> stall_num >> cow_num;
  if (board_num >= cow_num) {
    cout << cow_num << endl;
    return 0;
  }
  vector<int> cows(cow_num);
  vector<int> gaps;
  for (int i = 0; i < cow_num; i++) {
    cin >> cows[i];
  }
  sort(cows.begin(), cows.end());

  for (int i = 0; i < cow_num - 1; i++) {
    gaps.push_back(cows[i + 1] - cows[i] - 1);
  }
  sort(gaps.begin(), gaps.end());
  int res = cows.back() - cows[0] + 1;
  for (int i = 0; i < board_num - 1; i++) {
    res -= gaps[cow_num - i - 2];
  }
  cout << res << endl;
  return 0;
}