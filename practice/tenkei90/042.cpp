#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  const ll MOD = 1000000007;

  ll k; cin >> k;

  if (k % 9 != 0) {
    cout << 0 << '\n';
    return 0;
  }

  vector<ll> dp(100005);
  dp[0] = 1;

  for (ll i = 1; i <= k; ++i) {
    rep(j, 9) if (i - j - 1 >= 0) dp[i] += dp[i - j - 1];
    dp[i] %= MOD;
  }
  
  cout << dp[k] << '\n';
  return 0;
}