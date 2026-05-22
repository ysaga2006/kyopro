// https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_C

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  const ll INF = 1e15;
  ll v, e; cin >> v >> e;
  
  vector dp(v, vector<ll>(v, INF)); // dp[i][j]はiからjまでの最短距離
  for (ll i = 0; i < v; ++i) dp[i][i] = 0;

  for (ll i = 0; i < e; ++i) {
    ll s, t, d; cin >> s >> t >> d;
    dp[s][t] = d;
  }

  for (ll k = 0; k < v; ++k) {
    for (ll i = 0; i < v; ++i) {
      for (ll j = 0; j < v; ++j) {
        if (dp[i][k] != INF && dp[k][j] != INF) {
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        }
      }
    }
  }
  
  for (ll i = 0; i < v; ++i) {
    if (dp[i][i] < 0) {
      cout << "NEGATIVE CYCLE" << '\n';
      return 0;
    }
  }

  for (ll i = 0; i < v; ++i) {
    for (ll j = 0; j < v; ++j) {
      if (dp[i][j] == INF) cout << "INF";
      else cout << dp[i][j];

      if (j != v - 1) cout << " ";
    }
    cout << '\n';
  }

  return 0;
}