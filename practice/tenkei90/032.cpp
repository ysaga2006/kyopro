#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

const ll INF = 1000000000000000;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;

  vector a(n, vector<ll>(n));
  rep(i, n) rep(j, n) cin >> a[i][j];
  
  ll m;
  cin >> m;

  vector bad(n, set<ll>{});
  rep(i, m) {
    ll x, y;
    cin >> x >> y;
    x--; y--;
    bad[x].insert(y);
    bad[y].insert(x);
  }

  vector<ll> idx(n);
  iota(idx.begin(), idx.end(), 0);

  ll ans = INF;

  do {
    bool ok = true;
    rep(i, n - 1) {
      if (bad[idx[i]].contains(idx[i + 1])) ok = false;
    }

    if (ok == true) {
      ll sum = 0;
      rep(i, n) sum += a[idx[i]][i];
      ans = min(ans, sum);
    }
  } while (next_permutation(idx.begin(), idx.end()));

  if (ans == INF) ans = -1;

  cout << ans << '\n';
  return 0;
}