#include <iostream>
#include <vector>
#include <algorithm>

using std::greater;
using std::min;
using std::pair;
using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values)
{
  double value = 0.0;

  // write your code here
  int n = values.size();
  vector<pair<double, int>> fractions(n);
  for (int i = 0; i < n; ++i)
  {
    fractions[i] = {(values[i] * 1.0) / weights[i], i};
  }

  sort(fractions.begin(), fractions.end(), greater<pair<double, int>>());

  for (int i = 0; i < n && capacity > 0; ++i)
  {
    int weightUsed = min(weights[fractions[i].second], capacity);
    value += (1.0 * weightUsed * fractions[i].first);
    capacity -= weightUsed;
  }

  return value;
}

int main()
{
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++)
  {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
