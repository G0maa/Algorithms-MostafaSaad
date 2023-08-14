#include <bits/stdc++.h>
using namespace std;

void ThreeNPlusOne(int n)
{
  cout << n << ' ';

  if (n == 1)
    return;

  if (n % 2 == 0)
    ThreeNPlusOne(n / 2);
  else
    ThreeNPlusOne(3 * n + 1);
}

int main()
{
  ThreeNPlusOne(7);
  cout << "\nSalam :)\n";
  return 0;
}