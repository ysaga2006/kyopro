#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, w; cin >> n >> w;

  vector<ll> wei(n);
  vector<ll> val(n);

  for (ll i = 0; i < n; ++i) cin >> val[i] >> wei[i];

  vector dp(n + 1, vector<ll>(w + 1, 0));

  for (ll i = 0; i < n; ++i) { // i番目の品物について考える
    for (ll j = 0; j <= w; ++j) { // dp[i][j]の更新
      if (0 <= j - wei[i] && j - wei[i] <= w) {
        dp[i + 1][j] = max(dp[i][j - wei[i]] + val[i], dp[i][j]);
      } else {
        dp[i + 1][j] = dp[i][j];
      }
    }
  }

  cout << dp[n][w] << '\n';

  return 0;
}