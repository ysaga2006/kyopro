#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

const ll MOD = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, l;
  cin >> n >> l;

  vector<ll> dp(n + 1);  // i段目に登る場合の数(0段目は地面)
  dp[0] = 1;

  for (int i = 1; i <= n; i++) {
    if (i - l >= 0) {
      dp[i] = dp[i - 1] + dp[i - l];
    } else {
      dp[i] = dp[i - 1];
    }

    dp[i] %= MOD;
  }

  cout << dp[n] << '\n';
  return 0;
}