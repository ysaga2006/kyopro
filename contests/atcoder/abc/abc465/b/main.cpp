#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll x, y, l, r, a, b;
  cin >> x >> y >> l >> r >> a >> b;

    ll ans = 0;

    for (ll i = a; i < b; ++i) {
        if (l <= i && i < r) ans += x;
        else ans += y;
    }

    cout << ans << "\n";

  return 0;
}
