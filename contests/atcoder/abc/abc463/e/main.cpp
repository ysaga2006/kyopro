#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

template <class Cost>
struct Dijkstra {
  struct Edge {
    int to;
    Cost cost;
  };

  int n;
  vector<vector<Edge>> g;

  explicit Dijkstra(int n_) : n(n_), g(n) {}

  void add_edge(int from, int to, Cost cost, bool undirected = false) {
    g[from].push_back({to, cost});
    if (undirected) g[to].push_back({from, cost});
  }

  vector<Cost> solve(int s, Cost inf = numeric_limits<Cost>::max() / 4) const {
    vector<Cost> dist(n, inf);
    priority_queue<pair<Cost, int>, vector<pair<Cost, int>>, greater<pair<Cost, int>>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
      auto [d, v] = pq.top();
      pq.pop();
      if (d != dist[v]) continue;
      for (const auto& e : g[v]) {
        if (dist[e.to] > d + e.cost) {
          dist[e.to] = d + e.cost;
          pq.push({dist[e.to], e.to});
        }
      }
    }
    return dist;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m, y;
  cin >> n >> m >> y;

  Dijkstra<ll> g(n + 5);

  rep(i, m) {
    ll u, v, t;
    cin >> u >> v >> t;
    u--; v--;

    g.add_edge(u, v, t, true);
  }

  rep(i, n) {
    ll x;
    cin >> x;
    
    g.add_edge(i, n + 1, x);
    g.add_edge(n + 2, i, x);
  }

  g.add_edge(n + 1, n + 2, y);

  auto dist = g.solve(0);

  rep(i, n - 1) cout << dist[i + 1] << '\n';
  return 0;
}
