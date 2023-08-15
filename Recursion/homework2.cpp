#include <bits/stdc++.h>
using namespace std;

void rightMax(int arr[], int len, int start_position = 0)
{
  if (start_position == len - 1)
    return;

  rightMax(arr, len, start_position + 1);
  arr[start_position] = max(arr[start_position], arr[start_position + 1]);
}

int suffixSum(int arr[], int len, int elementCount)
{
  if (elementCount <= 0 || elementCount > len)
    return 0;

  return arr[len - elementCount] + suffixSum(arr, len, elementCount - 1);
}

int prefixSum(int arr[], int len, int elementCount)
{
  if (elementCount <= 0 || elementCount > len)
    return 0;

  return arr[elementCount - 1] + prefixSum(arr, len, elementCount - 1);
}

bool isPalindrome(int arr[], int len, int startPos = 0)
{
  if (startPos >= len)
    return true;

  if (arr[len - 1] != arr[startPos])
    return false;

  return isPalindrome(arr, len - 1, startPos + 1);
}

bool isPrefix(const string &main, const string &prefix, const int &startPos = 0)
{
  if ((int)main.size() < (int)prefix.size())
    return false;

  if (startPos >= (int)prefix.size())
    return true;

  if (main[startPos] != prefix[startPos])
    return false;

  return isPrefix(main, prefix, startPos + 1);
}

bool isPrime(int n, int divisor = 2)
{
  if (n == 1)
    return false;

  if (divisor * divisor > n)
    return true;

  if (n % divisor == 0)
    return false;

  return isPrime(n, divisor + 1);
}

int countPrimes(int start, int end)
{
  if (start > end)
    return 0;

  return isPrime(start) + countPrimes(start + 1, end);
}

int x[] = {1, 1, 0};
int y[] = {1, 0, 1};
int moves = 3;
int gridSum(int grid[100][100], int ROWS, int COLS, int row = 0, int col = 0)
{
  if (row >= ROWS || col >= COLS)
    return 0;

  int mx = -1;
  int mxIdx = 0;
  for (int i = 0; i < moves; ++i)
  {
    if (grid[row + x[i]][col + y[i]] > mx)
    {
      mx = grid[row + x[i]][col + y[i]];
      mxIdx = i;
    }
  }

  return grid[row][col] + gridSum(grid, ROWS, COLS, row + x[mxIdx], col + y[mxIdx]);
}

vector<long long> mem(51);
long long fib(long long n)
{
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;

  if (mem[n] != 0)
    return mem[n];

  mem[n - 1] = fib(n - 1);
  mem[n - 2] = fib(n - 2);

  return mem[n - 1] + mem[n - 2];
}

// TODO: Maybe abstract the printing repitive code in a utility function.
int main()
{
  int arr[] = {1, 3, 5, 7, 4, 2};
  int len = 6;

  // H2.1
  rightMax(arr, len);
  cout << "H2.1: rightMax: " << '\n';
  for (int i = 0; i < len; ++i)
    cout << arr[i] << ' ';
  cout << '\n';

  // H2.2:
  cout << "H2.2: suffixSum: " << suffixSum(arr, len, 1) << '\n';

  // H2.3
  cout << "H2.3: prefixSum: " << prefixSum(arr, len, 3) << '\n';

  // H2.4
  cout << "H2.4: isPalindrome: " << isPalindrome(arr, len) << '\n';

  // H2.5
  string m = "bc";
  string p = "bcc";
  cout << "H2.5: isPrefix: " << isPrefix(m, p) << '\n';

  // H2.6
  // Prints the digits of a number reversed,
  // if swapped, same but non-reversed.

  // H2.7
  // 100K+ => Segmentation fault
  cout << "H2.7: countPrimes: " << countPrimes(1, 100) << '\n';

  // H2.8
  int grid[100][100] = {
      {1, 7, 8},
      {4, 10, 11},
      {20, 5, 9}};

  int r = 3;
  int c = 3;

  cout << "H2.8: gridSum: " << gridSum(grid, 3, 3) << '\n';

  // H2.9:
  cout << "H2.9: fibonacci: " << fib(50) << '\n';
  cout << "\nSalam :)\n";
  return 0;
}