#include <bits/stdc++.h>
#include "../util.h"

using namespace std;

// This one adds the swap operation. Is it trivial?
void insertionSortV2(vector<int> &v)
{
  for (int i = 1; i < (int)v.size(); ++i)
    for (int j = i - 1; j >= 0 && v[j + 1] > v[j]; --j)
      swap(v[j + 1], v[j]);
}

void countSort(vector<int> &nums)
{
  int mx = nums[0];
  int mn = nums[0];
  for (int i = 1; i < nums.size(); ++i)
  {
    if (nums[i] > mx)
      mx = nums[i];
    if (nums[i] < mn)
      mn = nums[i];
  }

  int sz = abs(mn) + mx + 1;
  vector<int> mem(sz);
  for (int i = 0; i < nums.size(); ++i)
    mem[nums[i] + abs(mn)]++;

  int idx = 0;
  for (int i = 0; i < sz; ++i)
    while (mem[i]--)
      nums[idx++] = i - abs(mn);
}

int OO = 1e9 + 1;
int RANGE = 501; // for test case e.g. {-500, ... , 0}
void countSortRange(vector<int> &nums)
{
  int minN = OO, maxN = -OO;
  for (int i = 0; i < nums.size(); ++i)
  {
    if (nums[i] < minN)
      minN = nums[i];
    if (nums[i] > maxN)
      maxN = nums[i];
  }

  int shiftN = (maxN <= 0) ? abs(minN) : -minN;

  int sz = RANGE;
  vector<int> mem(sz);
  for (int i = 0; i < nums.size(); ++i)
    mem[nums[i] + shiftN]++;

  int idx = 0;
  for (int i = 0; i < sz; ++i)
    while (mem[i]--)
      nums[idx++] = i - shiftN;
}

void countSort(vector<string> &v)
{
  vector<queue<string>> vec(26);
  for (auto s : v)
    vec[s[0] - 'a'].push(s);

  int idx = 0;
  for (auto q : vec)
  {
    while (!q.empty())
    {
      v[idx++] = q.front();
      q.pop();
    }
  }
}

void countSortStrV2(vector<string> &v)
{
  vector<queue<string>> vec(26 * 26);
  for (auto s : v)
    vec[((s[0] - 97) * 26) + (s[1] - 97)].push(s);

  int idx = 0;
  for (auto q : vec)
  {
    while (!q.empty())
    {
      v[idx++] = q.front();
      q.pop();
    }
  }
}

int main()
{
  Util util;
  // vector<int> v = {5, 4, 3, 2, 1};
  // vector<int> v = {1, 2, 3, 4, 5};
  // vector<int> v = {5, 4};
  // vector<int> v = {4, 5};
  // vector<int> v = {-1, -2};
  // vector<int> v = {2, 2, 1, 1, 3, 3};
  vector<int> v = {3};

  // H1.1:
  insertionSortV2(v);
  util.PrintHomework("Insertion Sort V2");
  util.PrintVec(v);

  // H1.2:
  // LeetCode: https://leetcode.com/problems/sort-an-array/submissions/1025465231/
  vector<int> vneg = {4, -2, -1, 6, 3, 9, -20}; // vector<int> vneg = {5, -5};
  countSort(vneg);
  util.PrintHomework("Count Sort Negative");
  util.PrintVec(vneg);

  // H1.3
  vector<int> vn = {1000107, 1000035, 1000001};
  // vector<int> vn = {0, -1, -10, -125, -250, -499, -500};
  // vector<int> vn = {-1000, -1001, -1125, -1250, -1499, -1500};
  // vector<int> vn = {500, 499, 250, 125, 10, 1, 0};
  // vector<int> vn = {1500, 1499, 1250, 1125, 1001, 1000};
  // vector<int> vn = {-125, -125, -125, -128, 0, 0, 0, 2, 2, 2, 1, 1, 1}; // duplicates
  // vector<int> vn = {-125, -127, -128, 2, 1, 0}; // {-249, 0, 250}

  countSortRange(vn);
  util.PrintHomework("Count Sort Range");
  util.PrintVec(vn);

  // H1.4
  vector<string> vs = {"ziad", "belal", "adam", "baheir", "ali"};
  countSort(vs);
  util.PrintHomework("Count Sort for Strings V1");
  util.PrintVec(vs);

  // H1.5
  vector<string> vs2 = {"axz", "axa", "zzz", "abc", "abe"};
  countSortStrV2(vs2);
  util.PrintHomework("Count Sort for Strings V2");
  util.PrintVec(vs2);

  // H1.6
  // The accumlation trick helps in deciding the index for the number we're at,
  // because it counts (sums) all the numbers before it.
  // so 0 1 3 4 (e.g. 1 2 2 3), when you access count[array[i]] (e.g. i is 2)
  // it tells you to put it at the 3rd (- 1) index. then decrement by one.
  // The old count is 0 1 2 1, doesn't help in deciding where to put the number,
  // so we resorted to a second loop + idx variable.
  // Observe: We add more n operations.
  // Observe: We start from the end to make it a stable-sort algorithm.
  // Observe: count[] will have the same value regardless of the order of elements.

  cout << "\nSalam :)\n";
  return 0;
}