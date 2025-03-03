#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, V;
  cin >> N;

  vector<int> c(N);
  for (int i = 0; i < N; ++i) {
    cin >> c[i];
  }

  cin >> V;

  vector<int> dp(V + 1, INT_MAX);
  dp[0] = 0;

  for (int i = 0; i < N; ++i) {
    for (int j = c[i]; j <= V; ++j) {
      if (dp[j - c[i]] != INT_MAX) {
        dp[j] = min(dp[j], dp[j - c[i]] + 1);
      }
    }
  }

  if (dp[V] == INT_MAX) {
    cout << -1 << endl;
  } else {
    cout << dp[V] << endl;
  }

  return 0;
}
