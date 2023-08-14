#include <bits/stdc++.h>
using namespace std;

int Length3NPlusOne(int n)
{
  if (n == 1)
    return 1;

  if (n % 2 == 0)
    return 1 + Length3NPlusOne(n / 2);
  else
    return 1 + Length3NPlusOne(3 * n + 1);
}

int calcPow(int val, int p)
{
  // Maybe good for edge-cases, maybe not.
  if (p < 0)
    return 0;
  if (p == 0)
    return 1;
  if (p == 1)
    return val;

  return val * calcPow(val, p - 1);
}

int arrMax(int arr[], int len)
{
  if (len - 1 == 0)
    return arr[len - 1];

  return max(arrMax(arr, len - 1), arr[len - 1]);
}

int arrSum(int arr[], int len)
{
  if (len - 1 == 0)
    return arr[len - 1];

  return arr[len - 1] + arrSum(arr, len - 1);
}

double arrAvg(int arr[], int len)
{
  if (len - 1 == 0)
    return arr[len - 1];

  double sum = arrAvg(arr, len - 1) * (len - 1);

  return (double)(sum + arr[len - 1]) / len;
}

void arrInc(int arr[], int len)
{
  if (len - 1 == 0)
    return;

  arr[len - 1] += len - 1;

  arrInc(arr, len - 1);
}

void arrAccu(int arr[], int len)
{
  if (len - 1 == 0)
    return;

  arrAccu(arr, len - 1);
  arr[len - 1] += arr[len - 2];
}

void leftMax(int arr[], int len)
{
  if (len - 1 == 0)
    return;

  leftMax(arr, len - 1);
  arr[len - 1] = max(arr[len - 1], arr[len - 2]);
}

int main()
{
  // H1.1:
  cout << "Length is: " << Length3NPlusOne(6) << '\n';

  // H1.2:
  cout << "Power is: " << calcPow(7, 3) << '\n';

  // H1.3: (tested on: {1}, {1, 2}, {2, 1}, different places of max, negatives)
  int arr[] = {1, 8, 2, 10, 3};
  int len = 5;
  cout << "arrMax is: " << arrMax(arr, len) << '\n';

  // H1.4:
  cout << "arrSum is: " << arrSum(arr, len) << '\n';

  // H1.5:
  cout << "arrAvg is: " << arrAvg(arr, len) << '\n';

  // H1.6:
  arrInc(arr, len);
  cout << "arrInc is: " << '\n';
  for (int i = 0; i < len; ++i)
    cout << arr[i] << ' ';
  cout << '\n';

  // H1.7: Outputs: 1 10 14 27 34
  arrAccu(arr, len);
  cout << "arrAccu is: " << '\n';
  for (int i = 0; i < len; ++i)
    cout << arr[i] << ' ';
  cout << '\n';

  // H1.8:
  int arr1[] = {1, 3, 5, 7, 4, 2};
  int len1 = 6;
  leftMax(arr1, len1);
  cout << "leftMax is: " << '\n';
  for (int i = 0; i < len1; ++i)
    cout << arr1[i] << ' ';
  cout << '\n';

  cout << "\nSalam :)\n";
  return 0;
}
