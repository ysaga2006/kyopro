#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  const ll MOD = 1000000007;
  const string mozi = "atcoder";

  ll n; string s; cin >> n >> s;

  vector dp(n, vector<ll>(7, 0)); // i文字目まで見て、"atcoder"のj文字目まで選べる場合の数
  dp[0][0] = (s[0] == mozi[0]);

  for (ll i = 1; i < n; ++i) { // n文字目について考える
    for (ll j = 0; j < 7; ++j) {
      // n文字目を使わない場合
      dp[i][j] += dp[i - 1][j];
      // n文字目を使う場合
      if (s[i] == mozi[j]) {
        if (j == 0) {
          dp[i][j] += 1;
        } else {
          dp[i][j] += dp[i - 1][j - 1];
        }
      }

      dp[i][j] %= MOD;
    }
  }

  cout << dp[n - 1][6] << '\n';
  return 0;
}