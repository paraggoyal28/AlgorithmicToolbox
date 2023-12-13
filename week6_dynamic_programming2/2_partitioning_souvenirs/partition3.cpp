#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <numeric>

using std::accumulate;
using std::vector;

int partition3(vector<int> &A)
{
  int sum = accumulate(A.begin(), A.end(), 0);
  if (sum % 3 != 0)
  {
    return false;
  }
  int size = A.size();

  vector<vector<int>> dp(sum + 1, vector<int>(sum + 1, 0));
  dp[0][0] = true;

  // process the numbers one by one
  for (int i = 0; i < size; i++)
  {
    for (int j = sum; j >= 0; --j)
    {
      for (int k = sum; k >= 0; --k)
      {
        if (dp[j][k])
        {
          dp[j + A[i]][k] = true;
          dp[j][k + A[i]] = true;
        }
      }
    }
  }
  return dp[sum / 3][sum / 3];
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i)
  {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
