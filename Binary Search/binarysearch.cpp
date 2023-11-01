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

// I'm trying to make a general upperBound & lowerBound functions,
// that by changing possible() and limits, will work for any BS problem.

// index of first element larger than target.
// I couldn't generalize this function, as opposed to lowerBound.
int upperBound(const vector<int> &nums, const int &target)
{
  int len = (int)nums.size();
  if (len == 0)
    return len;

  int start = 0, end = len - 1;

  // ans initial value will be returned if target was not found (choose carefully!)
  int ans = len;

  while (start <= end)
  {
    int idx = start + (end - start) / 2;

    // In some problems you will need to change end & start.
    if (target < nums[idx])
      end = idx - 1, ans = idx;
    else
      start = idx + 1;

    // !possible()
    // if (nums[idx] <= target)
    //   start = idx + 1;
    // else
    //   end = idx - 1, ans = idx;
  }

  // add one for valid upper bound
  return ans;
}

// index of first element equal or larger than target.
int lowerBound(const vector<int> &nums, const int &target)
{
  int len = (int)nums.size();
  if (len == 0)
    return len;

  int start = 0, end = len - 1;

  // ans initial value will be returned if target was not found (choose carefully!)
  int ans = len;

  while (start <= end)
  {
    int idx = start + (end - start) / 2;

    if (target <= nums[idx])
      end = idx - 1, ans = idx;
    else
      start = idx + 1;
  }

  return ans;
}

// Borrowed from Prof.
double f(double x)
{
  return 4 * pow(x, 7) + 3 * pow(x, 5) - 1000;
}

// The while can be bounded by e.g. 100 iterations.
double binarySearchRealValues(double EPS = 1e-9)
{
  // Set them yourself
  double start = 0, end = 3;

  // for(int i = 0; i < 100; ++i) {
  //   // (What's inside the while loop)
  // }

  while (end - start > EPS)
  {
    double mid = start + (end - start) / 2;
    if (f(mid) < 0.0)
      start = mid;
    else
      end = mid;
  }

  return start;
}

int main()
{
  Util util;
  // see: https://leetcode.com/problems/binary-search/ & Fixed to prof's video.
  cout << "\nSalam :)\n";
  return 0;
}