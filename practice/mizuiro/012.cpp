#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m;
  cin >> n >> m;

  ll ans = 0;

  vector tomo(n, set<ll>{});

  for (ll i = 0; i < m; ++i) {
    ll x, y;
    cin >> x >> y;
    x--;
    y--;
    tomo[x].insert(y);
    tomo[y].insert(x);
  }

  for (ll bit = 0; bit < (1 << n); ++bit) {
    set<ll> team;
    for (ll i = 0; i < n; ++i) {
      if (bit & (1 << i)) {  // iを入れて良いかを検討する
        bool ok = true;
        for (auto& p : team) {
          if (!tomo[p].contains(i))
            ok = false;
        }
        if (ok == true)
          team.insert(i);
      }
    }

    // for (auto& p : team) cout << p << " ";
    // cout << '\n';

    ans = max(ans, ll(team.size()));
  }

  cout << ans << '\n';
  return 0;
}