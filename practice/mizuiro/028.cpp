#include <bits/stdc++.h>
using namespace std;
namespace rng = std::ranges;
namespace vw = std::views;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  ll n; cin >> n;

  vector g(n, vector<ll>{});
  vector<ll> dist(n, -1);
  queue<ll> togo;

  for (ll i = 0; i < n; ++i) {
    ll u, k; cin >> u >> k; u--;
    while (k--) {
      ll v; cin >> v; v--;
      g[u].push_back(v);
    }
  }

  togo.push(0);
  dist[0] = 0;
  while (!togo.empty()) {
    ll pos = togo.front();
    togo.pop();

    for (auto nev : g[pos]) {
      if (dist[nev] != -1) continue;
      dist[nev] = dist[pos] + 1;
      togo.push(nev);
    }
  }

  for (ll i = 0; i < n; ++i) {
    cout << i + 1 << " " << dist[i] << '\n';
  }

  return 0;
}