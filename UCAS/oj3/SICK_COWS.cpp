#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct SickArea {
  int length;
  bool isEdge;
};

int findMaxTime(SickArea sickArea) {
  if (sickArea.isEdge) return sickArea.length - 1;
  // length is even example: 4 -> 1
  // length is odd example: 3 -> 1
  return (sickArea.length - 1) / 2;
}

int findMinSickCow(SickArea sickArea, int time) {
  if (time == 0) return sickArea.length;
  int sickLength = 2 * time + 1;
  if (sickArea.length % sickLength == 0)
    return sickArea.length / sickLength;
  else
    return sickArea.length / sickLength + 1;
}

int main() {
  int cow_num;
  string cow;
  cin >> cow_num >> cow;
  vector<SickArea> sickAreas;
  int n = cow.size();
  for (int i = 0; i < n;) {
    if (cow[i] == '1') {
      int start = i;
      while (i < n && cow[i] == '1') {
        i++;
      }
      int end = i - 1;
      SickArea area;
      area.length = end - start + 1;
      area.isEdge = (start == 0 || end == n - 1);
      sickAreas.push_back(area);
    } else {
      i++;
    }
  }
  int maxTime = INT_MAX;
  for (auto sickArea : sickAreas) {
    maxTime = min(maxTime, findMaxTime(sickArea));
  }
  int res = 0;
  for (auto sickArea : sickAreas) {
    res += findMinSickCow(sickArea, maxTime);
  }
  cout << res << endl;
  return 0;
}