// https://onlinejudge.u-aizu.ac.jp/problems/DPL_2_A

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  const ll INF = 1e15;

  ll v, e; cin >> v >> e;
  
  vector dist(1 << v, vector<ll>(v, INF));

  for (ll i = 0; i < e; ++i) {
    ll s, t, d; cin >> s >> t >> d;
    dist[s][t] = d;
  }

  vector dp(1 << v, vector<ll>(v, INF)); // dp[s][v]は集合sを通って今現在vにいる時の最短距離
  dp[0][0] = 0;

  for (ll bit = 0; bit < (1 << v); ++bit) {
    for (ll i = 0; i < v; ++i) {
      if (dp[bit][i] == INF) continue;
      for (ll j = 0; j < v; ++j) {
        if (bit & (1 << j)) continue;
        if (dist[i][j] != INF) {
          ll nextbit = bit | (1 << j);
        }
      }
    }
  }


  return 0;
}