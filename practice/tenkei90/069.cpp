#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

const ll MOD = 1000000007;

ll modpow(ll x, ll n, ll mod) {
  ll ans = 1;
  x %= mod;
  while (n > 0) {
    if (n & 1) ans = (ans * x) % mod;
    x = (x * x) % mod;
    n >>= 1;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, k;
  cin >> n >> k;

  if (k == 1) {
    if (n == 1) {
      cout << 1 << '\n';
    } else {
      cout << 0 << '\n';
    }
  } else if (k == 2) {
    if (n == 1) {
      cout << 2 << '\n';
    } else if (n == 2) {
      cout << 2 << '\n';
    } else {
      cout << 0 << '\n';
    }
  } else if (k > 2) {
    if (n == 1) {
      cout << k % MOD << '\n';
    } else if (n == 2) {
      cout << (k % MOD) * ((k - 1) % MOD) % MOD << '\n';
    } else {
      cout << (k % MOD * (k - 1) % MOD * modpow(k - 2, n - 2, MOD)) % MOD << '\n';
    }
  }

  return 0;
}