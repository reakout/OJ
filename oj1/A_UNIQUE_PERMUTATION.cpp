#include <iostream>
#include <vector>
using namespace std;

// Used to even_extend a sub_perm 
void evenExtend(vector<int>& perm) {
  for (int i = 0; i < perm.size(); i++) {
    perm[i] = perm[i] * 2;
  }
  return;
}

// Used to odd_extend a sub_perm
void oddExtend(vector<int>& perm) {
  for (int i = 0; i < perm.size(); i++) {
    perm[i] = perm[i] * 2 + 1;
  }
  return;
}
// Used to compute the AAS_PERM.
void computeAAS(vector<int>& perm) {
  int perm_size = perm.size();

  // terminate state.
  if (perm_size == 1) {
    perm[0] = 0;
  }

  if (perm_size == 2) {
    perm[0] = 0;
    perm[1] = 1;
    return;
  }
  if (perm_size == 3) {
    perm[0] = 0;
    perm[1] = 2;
    perm[2] = 1;
    return;
  }

  vector<int> odd_part;
  vector<int> even_part;

  // odd situation.
  if (perm_size%2 == 1) {
    odd_part.resize(perm_size / 2);
    even_part.resize(perm_size / 2 + 1);
 }

  // even situation.
  else {
    odd_part.resize(perm_size / 2);
    even_part.resize(perm_size / 2);
  }

  computeAAS(odd_part);
  computeAAS(even_part);
  oddExtend(odd_part);
  evenExtend(even_part);
  for (int i = 0; i < even_part.size(); i++) {
    perm[i] = even_part[i];
  }
  for (int j = 0; j < odd_part.size(); j++) {
    perm[j + even_part.size()] = odd_part[j];
  }
  return;
}

// Used to print the AAS_PERM in the given order.
void printPerm(vector<int>& perm) {
  cout << perm.size() << ": ";
  for (int i = 0; i < perm.size() - 1; i++) {
    cout << perm[i] << " ";
  }
  cout << perm.back() << endl;
  return;
}



int main() {
  int input_num;
  vector<int> input_list;
  
  // input
  while(1) {
    cin >> input_num;
    if (input_num != 0) {
      input_list.push_back(input_num);
      continue;
    }
    break;
  }
  for (int i = 0; i < input_list.size(); i++) {
    int perm_size = input_list[i];
    vector<int> perm(perm_size);
    computeAAS(perm);
    printPerm(perm);
  }
  return 0;
}
