#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t; cin >> t;
  while (t--) {
    ll x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    ll dx = x1 - x2, dy = y1 - y2;
    ll dist = dx * dx + dy * dy;

    ll rdis = r1 + r2;
    ll rabs = abs(r1 - r2);

    if (rabs * rabs <= dist && dist <= rdis * rdis) cout << "Yes" << '\n';
    else cout << "No" << '\n';
  }

  return 0;
}
