#include <bits/stdc++.h>

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

// Note: couldn't solve it, had to see Prof. solution :c
// tl;dr: can he carry the msg? if Yes, where will it stop?
bool f(const vector<double> &positions, double k, double test)
{
  double msgPos = positions[0] + test;

  int n = sz(positions);
  for (int i = 1; i < n; ++i)
  {
    double maxMsgPos = msgPos + k;

    if (positions[i] - test > maxMsgPos)
      return false;

    msgPos = min(maxMsgPos, positions[i] + test);
  }
  return true;
}

double binarySearchRealValues(const vector<double> &positions, double k, double EPS = 1e-9)
{
  double start = 0, end = positions[sz(positions) - 1], ans;

  while (end - start > EPS)
  {
    double mid = start + (end - start) / 2;
    if (f(positions, k, mid))
      end = mid, ans = mid;
    else
      start = mid;
  }

  return ans;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // freopen("../in.txt", "r", stdin);
  // freopen("../out.txt", "w", stdout);

  int t = 1;
  cin >> t;
  while (t--)
  {
    double k;
    int n;

    cin >> k >> n;

    vector<double> positions(n);
    int i;
    fromTo(i, 0, n)
    {
      cin >> positions[i];
    }

    double ans = binarySearchRealValues(positions, k);

    cout << fixed;
    cout << setprecision(2) << ans << '\n';
  }

  // cout << "\nSalam :)\n";
  return 0;
}