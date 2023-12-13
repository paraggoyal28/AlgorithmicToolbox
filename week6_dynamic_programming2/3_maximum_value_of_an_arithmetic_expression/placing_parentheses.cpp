#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#define MAX 1e9;
#define MIN -1e9;

using std::max;
using std::min;
using std::string;
using std::vector;

long long m[30][30], M[30][30];
long long eval(long long a, long long b, char op)
{
  if (op == '*')
  {
    return a * b;
  }
  else if (op == '+')
  {
    return a + b;
  }
  else if (op == '-')
  {
    return a - b;
  }
  else
  {
    assert(0);
  }
}

void minAndMax(const string &exp, int start, int end)
{
  long long mini = MAX;
  long long maxi = MIN;
  for (int k = start + 1; k < end; k += 2)
  {
    long long a = eval(M[start][k - 1], M[k + 1][end], exp[k]);
    long long b = eval(M[start][k - 1], m[k + 1][end], exp[k]);
    long long c = eval(m[start][k - 1], M[k + 1][end], exp[k]);
    long long d = eval(m[start][k - 1], m[k + 1][end], exp[k]);
    mini = min(mini, min(a, min(b, min(c, d))));
    maxi = max(maxi, max(a, max(b, max(c, d))));
  }
  M[start][end] = maxi;
  m[start][end] = mini;
}

long long get_maximum_value(const string &exp)
{
  // write your code here
  int n = exp.length();

  for (int i = 0; i < n; i += 2)
  {
    m[i][i] = exp[i] - '0';
    M[i][i] = exp[i] - '0';
  }

  for (int len = 2; len < n; len += 2)
  {
    for (int i = 0; i < n - len; i += 2)
    {
      int j = i + len;
      minAndMax(exp, i, j);
    }
  }
  return M[0][n - 1];
}

int main()
{
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
