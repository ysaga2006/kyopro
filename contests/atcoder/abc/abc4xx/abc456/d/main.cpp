#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  string s; cin >> s;

  vector<ll> dp(3, 0); 

  for (char moji : s) {
    ll val = 1 + dp[0] + dp[1] + dp[2];
    if (moji == 'a') dp[0] = val % MOD;
    else if (moji == 'b') dp[1] = val % MOD;
    else if (moji == 'c') dp[2] = val % MOD;
  }

  cout << (dp[0] + dp[1] + dp[2]) % MOD << '\n';

  return 0;
}
