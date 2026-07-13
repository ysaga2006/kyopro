#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

const ll INF = -10000000000;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t; cin >> t;
  rep(ti, t) {
    ll n, m; cin >> n >> m;


    vector g(n, vector<ll>{});
    rep(i, m) {
      ll u, v; cin >> u >> v;
      u--; v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }

    vector<bool> visited(n, false);
    visited[0] = true;

    vector<ll> ans(n);

    auto dfs = [&](auto dfs, ll v, ll p) -> void {
      for (auto& nv : g[v]) {
        if (visited[nv] == true) continue;
        if (nv == p) continue;
        visited[nv] = true;
        ans[nv] = ans[v] + 1;
        dfs(dfs, nv, v);
      }
    };

    dfs(dfs, 0, -INF);

    rep(i, n) cout << ans[i] << '\n';
  }
  return 0;
}
