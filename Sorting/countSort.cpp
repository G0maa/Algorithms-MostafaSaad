#include <bits/stdc++.h>
using namespace std;

// Time O(n)
// Space O(mx)
// Properties: Non-adaptive, non-stable, not in-place (I think), non-online.
void countSort(vector<int> &v)
{
  // if there exists negative numbers =>
  // variable for mn, mem is abs(mn) + mx, shift everything by mn.
  // then re-shift when applying to v again.
  int mx = v[0];
  for (int i = 1; i < v.size(); ++i)
    if (v[i] > mx)
      mx = v[i];

  vector<int> mem(mx + 1);
  for (int i = 0; i < v.size(); ++i)
    mem[v[i]]++;

  int idx = 0;
  for (int i = 0; i < mx + 1; ++i)
    while (mem[i]--)
      v[idx++] = i;
}

int main()
{
  // vector<int> v = {5, 4, 3, 2, 1};
  // vector<int> v = {1, 2, 3, 4, 5};
  // vector<int> v = {5, 4};
  // vector<int> v = {4, 5};
  // vector<int> v = {-1, -2};
  vector<int> v = {2, 2, 1, 1, 3, 3};
  countSort(v);

  cout << "countSort is: " << '\n';
  for (int i = 0; i < (int)v.size(); ++i)
    cout << v[i] << ' ';
  cout << '\n';

  cout << "\nSalam :)\n";
  return 0;
}