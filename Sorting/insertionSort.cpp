#include <bits/stdc++.h>
using namespace std;

// Not by myself, first try I basically wrote selection sort.
void insertionSort(vector<int> &v)
{
  int len = (int)v.size();
  for (int i = 1; i < len; ++i)
  {
    int key = v[i];
    int idx = i - 1;
    while (idx >= 0 && key < v[idx])
    {
      v[idx + 1] = v[idx];
      idx--;
    }

    v[idx + 1] = key;
  }
}

int main()
{
  vector<int> v = {5, 4, 3, 2, 1};
  // vector<int> v = {1, 2, 3, 4, 5};
  // vector<int> v = {5, 4};
  // vector<int> v = {4, 5};
  // vector<int> v = {-1, -2};
  // vector<int> v = {2, 2, 1, 1, 3, 3};
  insertionSort(v);

  cout << "insertionSort is: " << '\n';
  for (int i = 0; i < (int)v.size(); ++i)
    cout << v[i] << ' ';
  cout << '\n';

  cout << "\nSalam :)\n";
  return 0;
}