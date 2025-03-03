#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define AMBIGIOUS -2
#define IMPOSSIBLE -1

struct sub_set_sum{
  long long sum;
  int size;
};

bool compareBySum(const sub_set_sum& a, long long sum) {
  return a.sum < sum;
}

bool compareForUpper(const sub_set_sum& a, const sub_set_sum& b) {
  return a.sum < b.sum;
}

void genAllSubsetSums(const vector<long long>& item_weight,
                      int start, int end,
                      vector<sub_set_sum>& sub_set_sums) {
  int n = end - start;
  for (int i = 0; i < (1 << n); i++) {
    long long sum = 0;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        sum += item_weight[start + j];
      }
    }
    int size = __builtin_popcount(i);
    sub_set_sums.push_back({sum, size});
  }
}

int meetInTheMiddle(const vector<long long>& item_weight, long long loss_weight) {
  int n = item_weight.size();

  vector<sub_set_sum> left_sum, right_sum;
  genAllSubsetSums(item_weight, 0, n / 2, left_sum);
  genAllSubsetSums(item_weight, n / 2, n, right_sum);

  sort(right_sum.begin(), right_sum.end(), [](const sub_set_sum& a, const sub_set_sum& b) {return a.sum < b.sum;});
  int res = IMPOSSIBLE;
  int res_num = 0;
  int found_solve = 0;
  vector<sub_set_sum> result;
  for (sub_set_sum left_sum_record : left_sum) {
    long long required = loss_weight - left_sum_record.sum;
    sub_set_sum temp = {required, 0};
    auto low_bound = lower_bound(right_sum.begin(), right_sum.end(), required, compareBySum);

    auto up_bound = upper_bound(right_sum.begin(), right_sum.end(), temp ,compareForUpper);

    // found solve.
    if (low_bound != right_sum.end() && low_bound->sum == required) {
      result.assign(low_bound, up_bound);
      for (auto solve_record : result) {
        int solve_size = solve_record.size + left_sum_record.size;
        if (solve_size != res) {
          res = solve_size;
          res_num++;
        }
        if (res_num > 1) return AMBIGIOUS;
      }
    }
  }
  return res;
}

int main() {
  int case_num, item_num;
  long long loss_weight, total_weight;
  vector<long long> item_weight;
  cin >> case_num;
  vector<int> res;
  // input.
  for (int i = 0; i < case_num; i++) {
    total_weight = 0;
    cin >> item_num >> loss_weight;
    item_weight.resize(item_num);
    for (int j = 0; j < item_num; j++) {
      cin >> item_weight[j];
      total_weight += item_weight[j];
    }
    res.push_back(meetInTheMiddle(item_weight, loss_weight));
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
