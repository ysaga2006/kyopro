// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1611&lang=jp

#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int solve() {
  ll n;
  cin >> n;
  if (n == 0)
    return -1;

  vector<ll> w(n);
  for (ll i = 0; i < n; ++i) cin >> w[i];

  vector dp(n + 1, (vector<ll>(n + 1, 0)));

  for (ll len = 2; len <= n; ++len) { // 区間の長さ[i, j)
    for (ll i = 0; i <= n - len; ++i) {
      ll j = i + len;
      if (dp[i + 1][j - 1] == len - 2) {
        if (abs(w[i] - w[j - 1]) <= 1) {
          dp[i][j] = dp[i + 1][j - 1] + 2;
        }
      }

      for (ll m = i + 1; m < j; ++m) {
        dp[i][j] = max(dp[i][j], dp[i][m] + dp[m][j]);
      }
    }
  }

  cout << dp[0][n] << '\n';
  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while (solve() == 0);

  return 0;
}