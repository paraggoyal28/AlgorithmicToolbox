#include <iostream>
#include <vector>
#define INT_MAX 1e9 + 7
using std::min;
using std::vector;
int get_change(int m)
{
  vector<int> coinsRequired(m + 1, INT_MAX);
  coinsRequired[0] = 0;
  vector<int> coins = {1, 3, 4};
  for (int change = 1; change <= m; ++change)
  {
    for (int val : coins)
    {
      if (val <= change)
      {
        coinsRequired[change] = min(coinsRequired[change], coinsRequired[change - val] + 1);
      }
    }
  }
  return coinsRequired[m];
}

int main()
{
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
