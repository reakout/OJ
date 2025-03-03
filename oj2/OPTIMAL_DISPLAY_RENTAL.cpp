#include <climits>
#include <iostream>
#include <vector>
using namespace std;
void travelToGetMinLeft(int n, vector<int>& leftMin, vector<int>& board_size,
                        vector<int>& board_price) {
  for (int i = 1; i < n - 1; i++) {
    for (int j = 0; j < i; j++) {
      if (board_size[i] > board_size[j]) {
        leftMin[i] = min(leftMin[i], board_price[j]);
      }
    }
  }
}

void travelToGetMinRight(int n, vector<int>& rightMin, vector<int>& board_size,
                         vector<int>& board_price) {
  for (int i = n - 2; i > 0; i--) {
    for (int j = n - 1; j > i; j--) {
      if (board_size[i] < board_size[j]) {
        rightMin[i] = min(rightMin[i], board_price[j]);
      }
    }
  }
}
int minPrice(int n, vector<int>& board_size, vector<int>& board_price) {
  vector<int> leftMin(n, INT_MAX);
  vector<int> rightMin(n, INT_MAX);
  travelToGetMinLeft(n, leftMin, board_size, board_price);
  travelToGetMinRight(n, rightMin, board_size, board_price);
  // cout << "leftMin: \n";
  // for (int i = 0; i < n; i++) {
  //   cout << leftMin[i] << " ";
  // }
  // cout << endl;
  // cout << "rightMin: \n";
  // for (int i = 0; i < n; i++) {
  //   cout << rightMin[i] << " ";
  // }
  // cout << endl;
  int minPrice = INT_MAX;
  for (int i = 1; i < n - 1; i++) {
    if (leftMin[i] != INT_MAX && rightMin[i] != INT_MAX) {
      minPrice = min(minPrice, leftMin[i] + board_price[i] + rightMin[i]);
    }
  }
  return minPrice == INT_MAX ? -1 : minPrice;
}

int main() {
  int n;
  cin >> n;
  vector<int> board_size(n), board_price(n);
  for (int i = 0; i < n; i++) {
    cin >> board_size[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> board_price[i];
  }
  cout << minPrice(n, board_size, board_price) << endl;
  return 0;
}
