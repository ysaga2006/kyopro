#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;

  vector<ll> a(n);
  vector<ll> b(n);
  vector g(n, vector<ll>{});

  for (ll i = 0; i < n - 1; ++i) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    g[b[i]].push_back(a[i]);
    g[a[i]].push_back(b[i]);
  }

  vector<ll> dist(n);
  const ll INF = 100100100;
  auto mindist = [&](ll start) {  // 頂点xから各頂点までの最短距離をdistに入れる
    for (ll i = 0; i < n; ++i) dist[i] = INF;

    queue<ll> Q;
    Q.push(start);
    dist[start] = 0;

    while (!Q.empty()) {
      ll pos = Q.front();
      Q.pop();

      for (ll to : g[pos]) {
        if (dist[to] == INF) {
          dist[to] = dist[pos] + 1;
          Q.push(to);
        }
      }
    }
  };

  mindist(0);
  ll mostdist = -1;
  ll farfromzero;
  for (ll i = 0; i < n; ++i) {
    if (mostdist < dist[i]) {
      mostdist = dist[i];
      farfromzero = i;
    }
  }

  mindist(farfromzero);
  ll ans = -1;
  for (ll i = 0; i < n; ++i) {
    ans = max(ans, dist[i]);
  }

  ans++;

  cout << ans << '\n';

  return 0;
}