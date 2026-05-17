#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n; cin >> n;

  struct Point {
    double x;
    double y;
  };

  vector<Point> p(n);
  for (ll i = 0; i < n; ++i) cin >> p[i].x >> p[i].y;

  vector<ll> v(n);
  iota(v.begin(), v.end(), 0);

  double sum = 0;
  do {
    for (ll i = 0; i < n - 1; ++i) {
      double dx = p[v[i]].x - p[v[i + 1]].x;
      double dy = p[v[i]].y - p[v[i + 1]].y;
      sum += hypot(dx, dy);
    }
  } while (next_permutation(v.begin(), v.end()));

  double bunbo = 1;
  
  for (ll i = 1; i <= n; ++i) {
    bunbo *= i;
  }

  cout << fixed << setprecision(10) << sum / bunbo << '\n';
  return 0;
}
