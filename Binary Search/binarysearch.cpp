#include <bits/stdc++.h>
#include "../util.h"
using namespace std;

int binarySearch(vector<int> &nums, int target)
{
  int start = 0, end = (int)nums.size() - 1;

  while (start <= end)
  {
    int idx = start + (end - start) / 2;

    if (target < nums[idx])
      end = idx - 1;
    else if (target > nums[idx])
      start = idx + 1;
    else
      return idx;
  }

  return -1;
}

// index of first element larger than target.
int upperBound(const vector<int> &nums, const int &target)
{
  int len = (int)nums.size();
  if (len == 0)
    return len;

  int start = 0, end = len - 1;

  int idx;
  while (start <= end)
  {
    idx = start + (end - start) / 2;

    if (target < nums[idx])
      end = idx - 1;
    else
      start = idx + 1;
  }

  if (nums[idx] <= target)
    idx++;

  return idx;
}

// index of first element equal or larger than target.
int lowerBound(const vector<int> &nums, const int &target)
{
  int len = (int)nums.size();
  if (len == 0)
    return len; // not sure about this handling.

  int start = 0, end = len - 1;

  int idx;
  while (start <= end)
  {
    idx = start + (end - start) / 2;

    if (target <= nums[idx])
      end = idx - 1;
    else
      start = idx + 1;
  }

  if (nums[idx] < target)
    idx++;

  return idx;
}

int main()
{
  Util util;
  // see: https://leetcode.com/problems/binary-search/ & Fixed to prof's video.
  cout << "\nSalam :)\n";
  return 0;
}