#include <iostream>
#include <string>
#include <vector>

using std::min;
using std::string;
using std::vector;

int edit_distance(const string &str1, const string &str2)
{
  int size1 = str1.length();
  int size2 = str2.length();
  vector<vector<int>> editDistanceDp(size1 + 1, vector<int>(size2 + 1, 0));
  for (int itr1 = 0; itr1 <= size1; ++itr1)
  {
    for (int itr2 = 0; itr2 <= size2; ++itr2)
    {
      if (itr1 == 0 && itr2 == 0)
        continue;
      else if (itr1 == 0)
        editDistanceDp[itr1][itr2] = itr2;
      else if (itr2 == 0)
        editDistanceDp[itr1][itr2] = itr1;
      else if (str1[itr1 - 1] == str2[itr2 - 1])
      {
        editDistanceDp[itr1][itr2] = editDistanceDp[itr1 - 1][itr2 - 1];
      }
      else
      {
        editDistanceDp[itr1][itr2] = 1 + min(editDistanceDp[itr1 - 1][itr2], min(editDistanceDp[itr1 - 1][itr2 - 1], editDistanceDp[itr1][itr2 - 1]));
      }
    }
  }
  return editDistanceDp[size1][size2];
}

int main()
{
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
