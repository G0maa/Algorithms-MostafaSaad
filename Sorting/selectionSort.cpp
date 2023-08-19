#include <bits/stdc++.h>
using namespace std;

int findMinIdx(const vector<int> &v, const int &start, const int &end)
{
  int minVal = v[start];
  int minIdx = start;
  for (int i = start + 1; i < end; ++i)
  {
    if (v[i] < minVal)
    {
      minVal = v[i];
      minIdx = i;
    }
  }

  return minIdx;
}

void selectionSort(vector<int> &v)
{
  // No need to visit last element.
  for (int i = 0; i < (int)v.size(); ++i)
  {
    int minIdx = findMinIdx(v, i, (int)v.size());
    swap(v[minIdx], v[i]);
  }
}

int main()
{
  // more simple than insertion sort.
  // Time O(n^2) but less efficient due to properties.
  // Space O(1)
  // Properties: In-Place, Non-Adaptive, Stable, Non-Online

  // TODO: Maybe create proper way to test code
  // vector<int> v = {5, 4, 3, 2, 1};
  // vector<int> v = {1, 2, 3, 4, 5};
  // vector<int> v = {5, 4};
  // vector<int> v = {4, 5};
  // vector<int> v = {-1, -2};
  vector<int> v = {2, 2, 1, 1, 3, 3};
  selectionSort(v);

  cout << "selectionSort is: " << '\n';
  for (int i = 0; i < (int)v.size(); ++i)
    cout << v[i] << ' ';
  cout << '\n';

  cout << "\nSalam :)\n";
  return 0;
}