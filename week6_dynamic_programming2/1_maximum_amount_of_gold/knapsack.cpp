#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w)
{
  // write your code here
  vector<int> currOptimal(W + 1, 0);
  vector<int> prevOptimal(W + 1, 0);
  int n = w.size();
  for (int itr = 1; itr <= n; ++itr)
  {
    for (int weight = 1; weight <= W; ++weight)
    {
      if (w[itr - 1] <= weight)
      {
        currOptimal[weight] = std::max(prevOptimal[weight], prevOptimal[weight - w[itr - 1]] + w[itr - 1]);
      }
    }
    prevOptimal = currOptimal;
  }
  return prevOptimal[W];
}

int main()
{
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++)
  {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
