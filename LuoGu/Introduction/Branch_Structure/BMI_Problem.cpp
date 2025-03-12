#include <iostream>
using namespace std;
int main() {
  float m, h, bmi;
  cin >> m >> h;
  bmi = m / (h * h);
  if (bmi < 18.5)
    cout << "UnderWeight" << endl;
  if (bmi >= 18.5 && bmi < 25)
    cout << "Normal" << endl;
  cout << bmi << endl << "Overweight"<<endl;
}