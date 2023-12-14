#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <limits.h>

using std::min;
using std::pair;
using std::string;
using std::vector;
struct Point
{
  int x, y;
};

bool cmpX(Point &start, Point &end)
{
  return start.x == end.x ? start.y < end.y : start.x < end.x;
}

bool cmpY(Point &start, Point &end)
{
  return start.y == end.y ? start.x < end.x : start.y < end.y;
}

double dist(Point p1, Point p2)
{
  return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double bruteForce(Point points[], int n)
{
  double min = INT_MAX;
  for (int i = 0; i < n; ++i)
  {
    for (int j = i + 1; j < n; ++j)
    {
      if (dist(points[i], points[j]) < min)
      {
        min = dist(points[i], points[j]);
      }
    }
  }
  return min;
}

double stripClosest(Point strip[], int size, double d)
{
  double min = d;

  for (int i = 0; i < size; ++i)
  {
    for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; ++j)
    {
      if (dist(strip[i], strip[j]) < min)
      {
        min = dist(strip[i], strip[j]);
      }
    }
  }
  return min;
}

double closestUtil(Point px[], Point py[], int n)
{
  if (n <= 3)
  {
    return bruteForce(px, n);
  }

  // Find the middle point
  int mid = n / 2;
  Point midPoint = px[mid];

  // Divide points in y sorted array around the vertical line.
  Point pyl[mid];
  Point pyr[n - mid];
  int li = 0, ri = 0;
  for (int i = 0; i < n; ++i)
  {
    if ((py[i].x < midPoint.x || (py[i].x == midPoint.x && py[i].y < midPoint.y)) && li < mid)
    {
      pyl[li++] = py[i];
    }
    else
    {
      pyr[ri++] = py[i];
    }
  }

  double dl = closestUtil(px, pyl, mid);
  double dr = closestUtil(px + mid, pyr, n - mid);

  double d = min(dl, dr);

  Point strip[n];
  int j = 0;
  for (int i = 0; i < n; ++i)
  {
    if (abs(py[i].x - midPoint.x) < d)
    {
      strip[j] = py[i], j++;
    }
  }

  return stripClosest(strip, j, d);
}

double minimal_distance(Point points[], int n)
{
  // write your code here
  Point Px[n];
  Point Py[n];
  for (int i = 0; i < n; ++i)
  {
    Px[i] = points[i];
    Py[i] = points[i];
  }

  std::sort(Px, Px + n, cmpX);
  std::sort(Py, Py + n, cmpY);

  return closestUtil(Px, Py, n);
}

int main()
{
  size_t n;
  std::cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  Point points[n];
  for (size_t i = 0; i < n; i++)
  {
    std::cin >> x[i] >> y[i];
    points[i].x = x[i];
    points[i].y = y[i];
  }
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(points, n) << "\n";
}
