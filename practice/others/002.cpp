#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const double EPS = 1e-5;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto f = [&](double x) {
    return x * x - 10 * sin(x) - 5;
  };

  double l, r; 
  cin >> l >> r;

  double m, prem = 0;
  
  for (ll i = 0; i < 100; ++i) {
    m = (l + r) / 2.0;

    if (f(l) * f(m) < 0) r = m;
    else if (f(m) * f(r) < 0) l = m;
    else if (f(m) == 0) break;
    else break;

    cout << m << '\n';

    if (i > 0 && fabs((m - prem) / m) <= EPS) break;
    prem = m;
  }

  cout << m << endl;
  return 0;
}