#include <bits/stdc++.h>
using namespace std;

// Note: int
#define sz(i) (int)i.size()
#define all(v) ((v).begin()), ((v).end())
#define allR(v) ((v).rbegin()), ((v).rend())
#define fromTo(var, from, to) for (int var = from; var < to; ++var)
#define fromToR(var, from, to) for (int var = from; var >= to; --var)
#define pb push_back

const double EPS = (1e-7); // Small number.

// Double compare, if equal return 0, x bigger return -1, y bigger return 1.
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1
                                                                     : 1; }

double f(const vector<double> &pieSizes, int numEaters, double test)
{
  for (int i = pieSizes.size() - 1; i >= 0 && numEaters > 0; --i)
  {
    if (pieSizes[i] >= test)
      numEaters -= floor(pieSizes[i] / test);
  }

  if (numEaters <= 0)
    return true;
  return false;
}

// O(t nlogn^2)
double binarySearchRealValues(const vector<double> &pieSizes, const int &numEaters, double EPS = 1e-5)
{
  double start = 0, end = 10000 * 10000 * M_PI, ans;

  while (end - start > EPS)
  {
    double mid = start + (end - start) / 2;
    if (f(pieSizes, numEaters, mid))
      start = mid, ans = mid;
    else
      end = mid;
  }

  return ans;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("../in.txt", "r", stdin);
  freopen("../out.txt", "w", stdout);

  int t = 1;
  cin >> t;
  while (t--)
  {
    int numPies, numEaters;
    cin >> numPies >> numEaters;
    numEaters++;

    vector<double> pieSizes(numPies);
    int i, x;
    fromTo(i, 0, numPies)
    {
      cin >> x;
      pieSizes[i] = x * x * M_PI;
    }

    double ans = binarySearchRealValues(pieSizes, numEaters);

    cout << fixed;
    cout << setprecision(4) << ans << '\n';
  }

  // cout << "\nSalam :)\n";
  return 0;
}
