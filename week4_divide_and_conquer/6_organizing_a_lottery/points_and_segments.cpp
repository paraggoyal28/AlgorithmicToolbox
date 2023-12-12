#include <iostream>
#include <vector>
#include <algorithm>

using std::pair;
using std::sort;
using std::vector;

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points)
{
  vector<int> cnt(points.size());
  sort(starts.begin(), starts.end());
  sort(ends.begin(), ends.end());

  for (int itr = 0; itr < points.size(); ++itr)
  {
    int point = points[itr];
    auto startingLS = lower_bound(ends.begin(), ends.end(), point);
    auto endingLS = upper_bound(starts.begin(), starts.end(), point);

    if (startingLS == ends.end() || endingLS == starts.begin())
    {
      cnt[itr] = 0;
      continue;
    }
    int start = startingLS - ends.begin();
    int end = endingLS - starts.begin() - 1;
    cnt[itr] = end - start + 1;
  }
  // write your code here
  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points)
{
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++)
  {
    for (size_t j = 0; j < starts.size(); j++)
    {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main()
{

  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++)
  {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++)
  {
    std::cin >> points[i];
  }
  // use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++)
  {
    std::cout << cnt[i] << ' ';
  }
}
