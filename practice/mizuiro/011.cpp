#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m; cin >> n >> m;

  ll ans = 0;
  
  vector tosee(m, set<ll>{});
  for (ll i = 0; i < m; ++i) {
    ll k; cin >> k;
    while (k--) {
      ll s; cin >> s; s--;
      tosee[i].insert(s);
    }
  }

  vector<ll> p(m);
  for (ll i = 0; i < m; ++i) cin >> p[i];

  for (ll bit = 0; bit < (1 << n); ++bit) {
    vector<ll> cnt(m);
    for (ll i = 0; i < n; ++i) {
      if (bit & (1 << i)) {
        for (ll j = 0; j < m; ++j) {
          if (tosee[j].contains(i)) cnt[j]++;
        }
      } 
    }

    bool ok = true;
    for (ll i = 0; i < m; ++i) {
      if (cnt[i] % 2 != p[i]) ok = false;
    }

    if (ok == true) ans++;
  }

  cout << ans << '\n';
  return 0;
}