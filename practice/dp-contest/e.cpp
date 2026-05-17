#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  const ll INF = 1LL<<60;
  const ll max_val = 10001;

  ll n, w;
  cin >> n >> w;

  vector dp(n + 1, vector<ll>(max_val, INF));  // dp[i][j]はi個目までで、価値jとなる時の、重さの最小値
  dp[0][0] = 0;

  for (ll i = 1; i <= n; ++i) {  // dp[i][j]について考える。
    ll wei, val;
    cin >> wei >> val;

    for (ll j = 0; j <= 10000; ++j) {
      if (j + val < 10001) {
        if (dp[i - 1][j] + wei < w) {
          dp[i][j + val] = min(dp[i - 1][j] + wei, dp[i - 1][j + val]);
        } else {
          dp[i][j + val] = dp[i - 1][j];
        }
      }
    }
  }

  for (ll i = 10000; i >= 0; --i) {
    if (dp[n][i] <= w) {
      cout << i << '\n';
      break;
    }
  }

  return 0;
}