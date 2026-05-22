#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

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
    if (undirected)
      g[to].push_back({from, cost});
  }

  vector<Cost> solve(int s, Cost inf = numeric_limits<Cost>::max() / 4) const {
    vector<Cost> dist(n, inf);
    priority_queue<pair<Cost, int>, vector<pair<Cost, int>>, greater<pair<Cost, int>>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
      auto [d, v] = pq.top();
      pq.pop();
      if (d != dist[v])
        continue;
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

  const ll INF = 1e18;

  ll n, m, k;
  cin >> n >> m >> k;

  vector<ll> togo(k);
  for (ll i = 0; i < k; ++i) {
    cin >> togo[i]; togo[i]--;
  }

  Dijkstra<ll> di(n);
  for (ll i = 0; i < n; ++i) {
    ll a, b, c; cin >> a >> b >> c; a--; b--;
    di.add_edge(a, b, c, true);
  }

  vector dist(n, vector<ll>(n, INF));

  for (ll i = 0; i < k; ++i) di.solve(togo[i]);


  return 0;
}
