#include <climits>
#include <iostream>
#include <vector>

using namespace std;
int minTransportTime(int n, int m, vector<int>& mi) {
  // minTime[i] : min time to carry i sheep to the other side.
  vector<int> minTime(n + 1, INT_MAX);
  // cross_time[i] : time to carry i sheep directly to the other side.
  vector<int> cross_time(n + 1);
  cross_time[0] = m;
  for (int i = 1; i <= n; ++i) {
    cross_time[i] = cross_time[i - 1] + mi[i - 1];
  }
  minTime[0] = m;
  minTime[1] = mi[0] + m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < i; ++j) {
      minTime[i] = min(minTime[i], minTime[i - j] + m + cross_time[j]);
    }
    minTime[i] = min(minTime[i], cross_time[i]);
  }
  return minTime[n];
}
int main() {
  int n, m;
  vector<int> mi;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    int temp;
    cin >> temp;
    mi.push_back(temp);
  }
  cout << minTransportTime(n, m, mi) << endl;
}