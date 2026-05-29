#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  double t, l, x, y; ll q; cin >> t >> l >> x >> y >> q;
  
  while (q--) {
    double e; cin >> e;
    cout << (180 / M_PI) * atan(((l / 2) * (-1 * sin(2 * M_PI * e / t - M_PI / 2) + 1)) / hypotf((l / 2) * (cos(2 * M_PI * e / t - M_PI / 2)) - y, x)) << '\n'; 
  }
  return 0;
}