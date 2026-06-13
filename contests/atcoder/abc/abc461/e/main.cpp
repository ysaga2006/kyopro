#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, q;
  cin >> n >> q;

  vector<ll> r(n), c(n);
  fenwick_tree<ll> gyo(q + 1), retu(q + 1);

  gyo.add(0, n);
  retu.add(0, n);

  ll ans = 0;
  for (ll i = 1; i <= q; i++) {
    ll op, x; cin >> op >> x;
    x--;

    if (op == 1) {
      ll old = r[x];
      ll before = retu.sum(0, old), after = retu.sum(0, i);

      ans += after - before;

      gyo.add(old, -1);
      r[x] = i;
      gyo.add(i, 1);
    } else {
      ll old = c[x];
      ll before = gyo.sum(old + 1, q + 1), after = gyo.sum(i + 1, q + 1);

      ans -= before - after;

      retu.add(old, -1);
      c[x] = i;
      retu.add(i, 1);
    }

    cout << ans << '\n';
  }
}