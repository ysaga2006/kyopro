#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  string s; cin >> s;
  ll n = s.size();

  vector<ll> dp(n);
  dp[0] = 1;

  for (ll i = 1; i < n; ++i) {
    if (s[i] != s[i - 1]) dp[i] = (dp[i - 1] + 1) % MOD;
    else dp[i] = 1;
  }

  ll ans = 0;
  for (ll i = 0; i < n; ++i) ans = (ans + dp[i]) % MOD;

  cout << ans << '\n';
  return 0;
}
