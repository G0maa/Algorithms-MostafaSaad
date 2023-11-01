#include <bits/stdc++.h>
#include "../util.h"

using namespace std;

// Note: int
#define sz(i) (int)i.size()
#define all(v) ((v).begin()), ((v).end())
#define allR(v) ((v).rbegin()), ((v).rend())
#define fromTo(var, from, to) for (int var = from; var < to; ++var)
#define fromToR(var, from, to) for (int var = from; var >= to; --var)
#define pb push_back
#define mp make_pair

typedef long long ll;
const ll OO = 1e9 + 5;     // Big number.
const double EPS = (1e-7); // Small number.

// Double compare, if equal return 0, x bigger return -1, y bigger return 1.
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1
                                                                     : 1; }
ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);

  Util util;

  cout << "\nSalam :)\n";
  return 0;
}