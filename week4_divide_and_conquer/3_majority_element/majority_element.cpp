#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right)
{
  int n = a.size();
  if (left == right)
    return -1;
  if (left + 1 == right)
    return a[left];
  int count = 1;
  int element = a[left];
  left += 1;
  while (left < right)
  {
    if (a[left] == element)
    {
      count += 1;
    }
    else
    {
      count -= 1;
    }
    if (count == 0)
    {
      element = a[left];
      count = 1;
    }
    left += 1;
  }
  count = 0;
  for (int i = 0; i < n; ++i)
  {
    if (element == a[i])
    {
      count += 1;
    }
  }
  return count > n / 2 ? element : -1;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i)
  {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
