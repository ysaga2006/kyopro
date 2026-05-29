#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, l, r, m; cin >> n >> l >> r >> m;
  ll ans = 0;
  while (n--) {
    ll p, k; cin >> p >> k;
    if (l <= p && p <= r && k <= m) ans++;
  }
  cout << ans << '\n';

  return 0;
}
