#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, W;
  cin >> n >> W;

  vector<ll> val(n + 1);
  vector<ll> wei(n + 1);

  for (ll i = 1; i < n + 1; ++i)
    cin >> val[i] >> wei[i];

  vector dp(n + 1, vector<ll>(W + 1, 0));  // dp[i][j]でi個目まで使った時の、重さj以下の最大価値

  for (ll i = 1; i <= n; ++i) {  // i個目の品物を考慮する(iは0からn - 1)
    for (ll j = 0; j <= W; ++j) {
      if (0 <= j - wei[i]) {
        dp[i][j] = max(dp[i][j - wei[i]] + val[i], dp[i - 1][j]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  cout << dp[n][W] << '\n';

  return 0;
}