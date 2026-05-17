#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll ans = 0;
  
  ll n, m; cin >> n >> m;

  vector<vector<ll>> g(n + 1);
  for (ll i = 0; i < m; ++i) {
    ll a, b; cin >> a >> b;
    g[a].push_back(b);
  }

  vector<bool> visited(n + 1, false);
  queue<ll> que;

  visited[1] = true;
  que.push(1);

  while (!que.empty()) {
    ll v = que.front();
    que.pop();
    ans++;

    for (auto nxv : g[v]) {
      if (!visited[nxv] == true) {
        visited[nxv] = true;
        que.push(nxv);
      }
    }
  }

  cout << ans << endl;

  return 0;
}
