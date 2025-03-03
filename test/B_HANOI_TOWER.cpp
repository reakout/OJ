#include<iostream>
#include<cmath>
void print_move(int i, int j) {
  std::cout << i << " " << j << std::endl;
}

void hanoi_tower(int disk_num, int start, int stay, int end) {
  if (disk_num == 0)
    return;
  hanoi_tower(disk_num -1, start, end, stay);
  print_move(start, end);
  hanoi_tower(disk_num - 1, stay, start, end);
}

int main() {
  int disk_num;
  std::cin >> disk_num;
  int total_move = std::pow(2, disk_num) - 1;
  std::cout << total_move << std::endl;
  hanoi_tower(disk_num, 1, 2, 3);
}