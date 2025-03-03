#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int findMaxFoodRoute(int m, int n, vector<vector<int>>& food) {
  vector<vector<vector<int>>> dp(
      m + n + 1, vector<vector<int>>(m + 1, vector<int>(m + 1, 0)));
  for (int step = 2; step <= m + n; ++step) {
    for (int x1 = max(1, step - n); x1 <= min(m, step - 1); ++x1) {
      for (int x2 = max(1, step - n); x2 <= min(m, step - 1); ++x2) {
        int y1 = step - x1, y2 = step - x2;
        if (y1 < 1 || y1 > n || y2 < 1 || y2 > n) continue;

        int max_food =
            max({dp[step - 1][x1 - 1][x2 - 1], dp[step - 1][x1 - 1][x2],
                 dp[step - 1][x1][x2 - 1], dp[step - 1][x1][x2]});

        dp[step][x1][x2] = max_food + food[x1 - 1][y1 - 1];
        if (x1 != x2) dp[step][x1][x2] += food[x2 - 1][y2 - 1];
      }
    }
  }
  return dp[m + n][m][m];
}
int main() {
  int m, n;
  cin >> m >> n;
  vector<vector<int>> food(m, vector<int>(n));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> food[i][j];
    }
  }
  cout << findMaxFoodRoute(m, n, food) << endl;
  return 0;
}