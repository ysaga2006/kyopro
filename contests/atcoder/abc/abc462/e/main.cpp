#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t; cin >> t;
  rep(i, t) {

    ll ans;
    ll a, b, x, y; cin >> a >> b >> x >> y;

    auto f = [&](ll x, ll y) {
      x = abs(x), y = abs(y);
      return min(x, y) * 2 * min(a, b) + (abs(x - y) / 2) * min(a + b, 4 * min(a, b));
    };

    if ((abs(x) + abs(y)) % 2 == 0) ans = f(x, y);
    else ans = min({a + f(x - 1, y), a + f(x + 1, y), b + f(x, y - 1), b + f(x, y + 1)});

    cout << ans << '\n';
  }
  return 0;
}
