#include <iostream>
#include <vector>

using std::vector;

long long merge(vector<int> &a, vector<int> &b, size_t left, size_t ave, size_t right)
{
  int l = left;
  int r = ave + 1;
  long long inversions = 0;
  int k = left;
  while (l <= ave && r <= right)
  {
    if (a[l] <= a[r])
    {
      b[k++] = a[l++];
    }
    else
    {
      inversions += ave - l + 1;
      b[k++] = a[r++];
    }
  }
  while (l <= ave)
  {
    b[k++] = a[l++];
  }
  while (r <= right)
  {
    b[k++] = a[r++];
  }
  for (int i = left; i <= right; ++i)
  {
    a[i] = b[i];
  }
  return inversions;
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right)
{
  long long number_of_inversions = 0;
  if (right <= left)
    return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave + 1, right);
  // write your code here
  number_of_inversions += merge(a, b, left, ave, right);
  return number_of_inversions;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++)
  {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size() - 1) << '\n';
}
