#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll v, e, r;
  cin >> v >> e >> r;

  vector g(v, vector<pair<ll, ll>>{});

  for (ll i = 0; i < e; ++i) {
    ll s, t, d;
    cin >> s >> t >> d;
    g[s].push_back({t, d});
  }

  // 始点から各点への最短距離
  vector<ll> dist(v, INF);
  dist[r] = 0;

  // 最短経路の候補の距離と頂点番号
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
  pq.push({0, r});

  while (!pq.empty()) {
    auto [d, V] = pq.top();
    pq.pop();

    if (dist[V] < d) continue;

    for (auto& edge : g[V]) {
      auto [nextv, cost] = edge;
      if (dist[V] + cost < dist[nextv]) {
        dist[nextv] = dist[V] + cost;
        pq.push({dist[nextv], nextv});
      }
    }
  }

  for (ll i = 0; i < v; ++i) {
    if (dist[i] == INF) cout << "INF" << '\n';
    else cout << dist[i] << '\n';
  }

  return 0;
}