#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll powmod(ll a, ll n, ll mod) {
  ll res = 1;
  a %= mod;
  while (n > 0) {
    if (n & 1) {
      res = res * a % mod;
    }
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

ll gyakugen(ll a, ll mod) {
  return powmod(a, mod - 2, mod);
}

ll kaizyo(ll n, ll mod) {  // n!の計算
  ll res = 1;
  for (ll i = 1; i <= n; ++i) {
    res = (res * i) % mod;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  const ll MOD = 1'000'000'007;

  ll w, h;
  cin >> w >> h;
  w--;
  h--;
  ll ans = 1;

  ans = (ans * kaizyo(w + h, MOD)) % MOD;
  ans = (ans * gyakugen(kaizyo(w, MOD) * kaizyo(h, MOD), MOD)) % MOD;

  cout << ans % MOD << '\n';

  return 0;
}