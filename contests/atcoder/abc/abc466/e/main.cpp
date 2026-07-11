#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

const ll INF = 1000000000000000;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll ans = -INF;

  ll n, k;
  cin >> n >> k;

  vector<ll> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];

  vector dp(n + 1, vector<vector<ll>>(k + 1, vector<ll>(2, -INF)));
  dp[0][0][0] = 0;

  rep(i, n) rep(j, k + 1) {
    if (dp[i][j][0] != -INF) dp[i + 1][j][0] = max(dp[i + 1][j][0], dp[i][j][0] + a[i]);
    if (dp[i][j][1] != -INF) dp[i + 1][j][0] = max(dp[i + 1][j][0], dp[i][j][1] + a[i]);

    if (dp[i][j][1] != -INF) dp[i + 1][j][1] = max(dp[i + 1][j][1], dp[i][j][1] + b[i]);
    if (j >= 1 && dp[i][j - 1][0] != -INF) dp[i + 1][j][1] = max(dp[i + 1][j][1], dp[i][j - 1][0] + b[i]);
  }

  rep(i, k + 1) ans = max({ans, dp[n][i][0], dp[n][i][1]});

  cout << ans << '\n';
  return 0;
}
