#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n)
{
  vector<int> summands;

  int start = 1;
  int sum = 0;
  while (sum < n)
  {
    if (sum + start <= n)
      summands.push_back(start);
    else
      summands[summands.size() - 1] += n - sum;
    sum += start;
    start += 1;
  }

  return summands;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i)
  {
    std::cout << summands[i] << ' ';
  }
}
