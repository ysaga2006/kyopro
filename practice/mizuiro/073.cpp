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

const ll mod = 1'000'000'007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll x, y;
  cin >> x >> y;

  ll p = (2 * x - y), q = (2 * y - x);

  if (p % 3 != 0 || q % 3 != 0 || p < 0 || q < 0) {
    cout << 0 << '\n';
    return 0;
  }

  p /= 3; q /= 3;
  ll ans = 1;

  ans = (ans * kaizyo(p + q, mod)) % mod;
  ans = (ans * gyakugen(kaizyo(p, mod) * kaizyo(q, mod), mod)) % mod;

  cout << ans % mod << '\n';

  return 0;
}