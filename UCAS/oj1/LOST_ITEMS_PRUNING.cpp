#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

unordered_map<string, bool> m_map;

string getKey(int index, long long current_sum) {
  return to_string(index) + ":" + to_string(current_sum);
}

#define AMBIGIOUS 0
#define IMPOSSIBLE -1

void findItemNum(const vector<long long>& item_weight, int index,
                 long long current_sum, long long loss_weight, int count, int& count_res,
                 int& solve_count, long long remainning_weight) {
  if (current_sum > loss_weight || solve_count > 1) return;
  if (current_sum == loss_weight && count != 0) {
    if (count_res == -1 || count != count_res) {
      count_res = count;
      solve_count++;
      if (solve_count > 1) return;
    }
    if (item_weight[index] != 0)
      return;
  }

  if (index == item_weight.size()) return;

  if (current_sum + remainning_weight < loss_weight) return;

  string key = getKey(index, current_sum);
  if (m_map.find(key) != m_map.end() && item_weight[index] != 0) return;

  // Do Not choose current item.
  findItemNum(item_weight, index + 1, current_sum, loss_weight,
              count , count_res, solve_count,
              remainning_weight - item_weight[index]);

  // Choose current item.
  findItemNum(item_weight, index + 1, current_sum + item_weight[index],
              loss_weight, count + 1, count_res, solve_count,
              remainning_weight - item_weight[index]);
  m_map[key] = true;
  return;
}

int main() {
  int case_num, item_num;
  long long loss_weight, total_weight;
  vector<long long> item_weight;
  cin >> case_num;
  vector<int> res(case_num);
  // input.
  for (int i = 0; i < case_num; i++) {
    total_weight = 0;
    m_map.clear();
    cin >> item_num >> loss_weight;
    item_weight.resize(item_num);
    for (int j = 0; j < item_num; j++) {
      cin >> item_weight[j];
      total_weight += item_weight[j];
    }
    int count_res = -1;
    int solve_count = 0;
    sort(item_weight.begin(), item_weight.end(), greater<long long>());
    findItemNum(item_weight, 0, 0, loss_weight, 0, count_res,
                solve_count, total_weight);
    if (solve_count > 1) {
      res[i] = AMBIGIOUS;
    }
    else if (solve_count == 0) {
      res[i] = IMPOSSIBLE;
    } else {
      res[i] = count_res;
    }
  }
  // output.
  for (int j = 0; j < case_num; j++) {
    if (res[j] == IMPOSSIBLE) {
      cout << "Case #" << j + 1 << ": IMPOSSIBLE" << endl;
      continue;
    }
    if (res[j] == AMBIGIOUS) {
      cout << "Case #" << j + 1 << ": AMBIGIOUS" << endl;
      continue;
    }
    cout << "Case #" << j + 1 << ": " << res[j] << endl;
  }
}
