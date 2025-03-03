#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  int s, v;
  cin >> s >> v;
  int time_on_road;
  int is_odd = (s % v == 0) ? 0 : 1;
  time_on_road = s / v;
  int time_to_school = time_on_road + is_odd + 10;
  int hour_to_school = time_to_school / 60;
  int min_to_school = time_to_school % 60;
  int hour =
      (7 - hour_to_school >= 0) ? 7 - hour_to_school : 31 - hour_to_school;
  int min = 60 - min_to_school;
  cout << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0')
       << min << endl;
  return 0;
}
