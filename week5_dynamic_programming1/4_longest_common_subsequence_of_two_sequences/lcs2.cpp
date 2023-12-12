#include <iostream>
#include <vector>

using std::vector;

int lcs2(vector<int> &a, vector<int> &b)
{
  int aS = a.size();
  int bS = b.size();
  vector<vector<int>> lcsDp(aS + 1, vector<int>(bS + 1, 0));
  for (int itr1 = 1; itr1 <= aS; ++itr1)
  {
    for (int itr2 = 1; itr2 <= bS; ++itr2)
    {
      if (a[itr1 - 1] == b[itr2 - 1])
      {
        lcsDp[itr1][itr2] = lcsDp[itr1 - 1][itr2 - 1] + 1;
      }
      else
      {
        lcsDp[itr1][itr2] = std::max(lcsDp[itr1 - 1][itr2], lcsDp[itr1][itr2 - 1]);
      }
    }
  }
  return lcsDp[aS][bS];
}

int main()
{
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++)
  {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++)
  {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
