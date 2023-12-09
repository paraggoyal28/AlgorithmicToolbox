#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::min;
using std::vector;

struct Segment
{
  int start, end;
};

bool cmp(Segment &a, Segment &b)
{
  return a.start == b.start ? a.end < b.end : a.start < b.start;
}

vector<int> optimal_points(vector<Segment> &segments)
{
  vector<int> points;
  // write your code here
  sort(segments.begin(), segments.end(), cmp);

  int end = segments[0].end;

  for (size_t i = 0; i < segments.size(); ++i)
  {
    if (segments[i].start <= end)
    {
      end = min(segments[i].end, end);
    }
    else
    {
      points.push_back(end);
      end = segments[i].end;
    }
  }
  points.push_back(end);
  return points;
}

int main()
{
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i)
  {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i)
  {
    std::cout << points[i] << " ";
  }
}
