#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // 前日に行った行動とi日時点での幸福度の最大値をd[c][i]でもつ。

  ll n;
  cin >> n;
  vector dp(3, vector<ll>(n + 1, 0));

  dp[0][0] = 0;
  dp[1][0] = 0;
  dp[2][0] = 0;

  for (ll i = 1; i <= n; ++i) {
    ll a, b, c;
    cin >> a >> b >> c;
    dp[0][i] = max(dp[1][i - 1], dp[2][i - 1]) + a;
    dp[1][i] = max(dp[2][i - 1], dp[0][i - 1]) + b;
    dp[2][i] = max(dp[0][i - 1], dp[1][i - 1]) + c;
  }

  cout << max({dp[0][n], dp[1][n], dp[2][n]}) << '\n';

  return 0;
}