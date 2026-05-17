#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m, q; cin >> n >> m >> q;

  vector kukan(n + 1, vector<ll>(n + 1, 0));

  while (m--) {
    ll l, r; cin >> l >> r;
    kukan[l][r]++;
  }

  // (0, 0)から(i, j)までの個数
  for (ll i = 0; i < n; ++i) for (ll j = 0; j < n + 1; ++j) {
    kukan[i + 1][j] += kukan[i][j];
  }

  for (ll i = 0; i < n + 1; ++i) for (ll j = 0; j < n; ++j) {
    kukan[i][j + 1] += kukan[i][j];
  }

  while (q--) {
    ll p, q; cin >> p >> q;
    
  }
  return 0;
}