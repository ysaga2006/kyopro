#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // dp[i][j]は、i個目まで考えた時の、重さがj以下での価値の総和
  ll n, w; cin >> n >> w;

  vector dp(n + 1, vector<ll>(w + 1, 0));

  for (ll i = 1; i <= n; ++i) { // i個目について考える。

    ll wei, val; cin >> wei >> val;

    for (ll j = 0; j <= w; ++j) { // dp[i][j]について更新する。

      if (j >= wei) { // weiを選ぶとき
        dp[i][j] = max(dp[i - 1][j - wei] + val, dp[i - 1][j]); 
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  cout << dp[n][w] << '\n';

  return 0;
}