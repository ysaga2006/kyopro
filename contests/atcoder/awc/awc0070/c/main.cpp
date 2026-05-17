#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

const ll MOD = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n; string s; cin >> n >> s;

  vector<ll> ok(n);
  for (ll i = 0; i < n; ++i) {
    if (s[i] == '.') ok[i] = 1;
    else ok[i] = 0;
  }

  vector<ll> memo(n);
  memo[0] = ok[0] * ok[0];
  memo[1] = ok[1] * (ok[1] + memo[0]);
  memo[2] = ok[2] * (ok[2] + (memo[0] + memo[1]));

  for (ll i = 3; i < n; ++i) {
    memo[i] = ok[i] * (memo[i - 1] + memo[i - 2] + memo[i - 3]) % MOD;
  }

  cout << memo[n - 1] << '\n';
  return 0;
}
