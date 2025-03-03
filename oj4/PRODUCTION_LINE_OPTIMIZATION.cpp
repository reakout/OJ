#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, p, m;
  cin >> n >> p >> m;
  vector<pair<int, int>> lines(p);
  int max_capacity = 0;
  for (int i = 0; i < p; ++i) {
    cin >> lines[i].first >> lines[i].second;
    max_capacity = max(max_capacity, lines[i].second);
  }
  if (m / max_capacity > n) {
    cout << -1 << endl;
    return 0;
  }
  vector<int> dp(m + max_capacity + 1, INT_MAX);
  dp[0] = 0;

  for (int i = 1; i <= n; ++i) {
    for (auto &line : lines) {
      int cost = line.first;
      int capacity = line.second;

      for (int j = m + max_capacity; j >= capacity; --j) {
        if (dp[j - capacity] != INT_MAX) {
          dp[j] = min(dp[j], dp[j - capacity] + cost);
        }
      }
    }
  }

  int min_cost = INT_MAX;
  for (int i = m; i <= m + max_capacity; ++i) {
    min_cost = min(min_cost, dp[i]);
  }

  cout << min_cost << endl;
  return 0;
}
