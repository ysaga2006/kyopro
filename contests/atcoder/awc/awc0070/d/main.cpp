#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll ans = 0;
  ll n, m, q; cin >> n >> m >> q;

  vector b(n, vector<ll>(m));
  vector s(n + 1, vector<ll>(m + 1, 0));

  for (ll i = 0; i < n; ++i) for (ll j = 0; j < m; ++j) cin >> b[i][j];

  while (q--) {
    ll r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
    r1--; c1--; r2--; c2--;

    s[r1][c1]++;
    s[r1][c2 + 1]--;
    s[r2 + 1][c1]--;
    s[r2 + 1][c2 + 1]++;
  }

  for (ll i = 0; i < n - 1; ++i) for (ll j = 0; j < m; ++j) {
    s[i + 1][j] += s[i][j];
  }

  for (ll i = 0; i < n; ++i) for (ll j = 0; j < m - 1; ++j) {
    s[i][j + 1] += s[i][j];
  }

  for (ll i = 0; i < n; ++i) for (ll j = 0; j < m; ++j) {
    if (s[i][j] % 2 == 0) s[i][j] = 1;
    else s[i][j] = 2;
  }

  for (ll i = 0; i < n; ++i) for (ll j = 0; j < m; ++j) ans += b[i][j] * s[i][j];

  cout << ans << '\n';
  return 0;
}
