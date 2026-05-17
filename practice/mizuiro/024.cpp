#include <bits/stdc++.h>
using namespace std;
namespace rng = std::ranges;
namespace vw = std::views;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;

  vector g(n, vector<ll>{});
  vector<ll> d(n, -1);
  vector<ll> f(n, -1);

  for (ll i = 0; i < n; ++i) {
    ll u, k;
    cin >> u >> k;
    u--;

    while (k--) {
      ll v;
      cin >> v;
      v--;
      g[u].push_back(v);
    }
  }

  ll time = 0;
  auto dfs = [&](auto dfs, ll v) -> void {
    time++;
    d[v] = time;

    for (auto nev : g[v]) {
      if (d[nev] != -1)
        continue;
      dfs(dfs, nev);
    }

    time++;
    f[v] = time;
  };

  dfs(dfs, 0);

  for (ll i = 0; i < n; ++i) {
    cout << i + 1 << " " << d[i] << " " << f[i] << '\n';
  }

  return 0;
}