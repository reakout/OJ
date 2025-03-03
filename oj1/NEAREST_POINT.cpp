#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <cfloat>
#include <iomanip>
using namespace std;
#define AGENT 0
#define POSITION 1

struct Point {
  double x,y;
  bool type;
};


bool compareX (const Point& point1, const Point& point2) {
  return point1.x < point2.x;
}

bool compareY (const Point& point1, const Point& point2) {
  return point1.y < point2.y;
}

double distance (Point point1, Point point2) {
  return point1.type == point2.type? DBL_MAX :
         sqrt((point1.x - point2.x) * (point1.x - point2.x) +
              (point1.y - point2.y) * (point1.y - point2.y));
}

double minDistanceIn3Points(vector<Point> points) {
  double res = DBL_MAX;
  double d;
  if (points.size() == 1) return DBL_MAX;
  for (int i = 0; i < points.size() - 1; i++) {
    for (int j = i + 1; j < points.size(); j++) {
      d = distance(points[i], points[j]);
      if (d < res)
        res = d;
    }
  }
  return res;
}

double nearestDistanceRecursive(vector<Point>points_x,
                                vector<Point>points_y) {
  if (points_x.size() <= 3)
    return minDistanceIn3Points(points_x);
  double d_left, d_right, d_s;
  // maintain left_x, right_x.
  size_t mid = points_x.size() / 2;
  vector<Point> left_x(points_x.begin(), points_x.begin() + mid);
  vector<Point> right_x(points_x.begin() + mid, points_x.end());
  // maintain left_y, right_y.
  vector<Point> left_y, right_y;
  double x_mid = points_x[mid].x;
  for (auto point : points_y) {
    if (point.x < x_mid)
      left_y.push_back(point);
    else
      right_y.push_back(point);
  }

  // devide.
  d_left = nearestDistanceRecursive(left_x, left_y);
  d_right = nearestDistanceRecursive(right_x, right_y);

  // merge.
  double d = min(d_left, d_right);
  vector<Point>s;
  for (auto point : points_y) {
    if (point.x >= points_x[mid].x - d && point.x <= points_x[mid].x + d)
      s.push_back(point);
  }
  int visit_point = 0;
  d_s = DBL_MAX;
  for (int i = 0 ; i < s.size(); i++) {
    int visit_num = min(7, (int)s.size() - i);
    for (int j = 0; j < visit_num; j++) {
      d_s = min(d_s, distance(s[i], s[i + j]));
    }
  }
  return min(d,d_s);
}

double nearestDistance(vector<Point> points) {
  vector<Point> points_x = points;
  vector<Point> points_y = points;
  sort(points_x.begin(), points_x.end(),compareX);
  sort(points_y.begin(), points_y.end(), compareY);
  return nearestDistanceRecursive(points_x, points_y);
}

int main() {
  int round_num,point_num;
  double res_per_round;
  std::cin >> round_num;
  std::vector<double> res(round_num);
  for (int round = 0; round < round_num; round++) {
    // input
    cin >> point_num;
    vector<Point>points(2 * point_num);
    for (int j = 0; j < point_num; j++) {
      cin >> points[j].x >> points[j].y;
      points[j].type = AGENT;
    }
    for (int j = 0; j < point_num; j++) {
      cin >> points[point_num + j].x
               >> points[point_num + j].y;
      points[point_num + j].type = POSITION;
    }
    res[round] = nearestDistance(points);
  }
  //output
  for (int i = 0; i < round_num; i++)
    cout << fixed << setprecision(3)
         << res[i] << endl;
  return 0;
}
