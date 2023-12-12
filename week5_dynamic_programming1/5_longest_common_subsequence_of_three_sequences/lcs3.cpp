#include <iostream>
#include <vector>

using std::vector;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c)
{
  // write your code here
  int as = a.size();
  int bs = b.size();
  int cs = c.size();
  vector<vector<vector<int>>> lcs(as + 1, vector<vector<int>>(bs + 1, vector<int>(cs + 1, 0)));

  for (int i = 1; i <= as; ++i)
  {
    for (int j = 1; j <= bs; ++j)
    {
      for (int k = 1; k <= cs; ++k)
      {
        if (a[i - 1] == b[j - 1] && a[i - 1] == c[k - 1])
        {
          lcs[i][j][k] = lcs[i - 1][j - 1][k - 1] + 1;
        }
        else
        {
          lcs[i][j][k] = std::max(lcs[i - 1][j][k], std::max(lcs[i][j - 1][k], lcs[i][j][k - 1]));
        }
      }
    }
  }
  return lcs[as][bs][cs];
}

int main()
{
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++)
  {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++)
  {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++)
  {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
