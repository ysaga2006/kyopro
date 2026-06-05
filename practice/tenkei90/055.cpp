#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, p, q; cin >> n >> p >> q;
  
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll cnt = 0;
  for (ll i = 0; i < n; ++i) {
    for (ll j = i + 1; j < n; ++j) {
      for (ll k = j + 1; k < n; ++k) {
        for (ll l = k + 1; l < n; ++l) {
          for (ll m = l + 1; m < n; ++m) {
            if (a[i] * a[j] % p * a[k] % p * a[l] % p * a[m] % p == q) cnt++;
          }
        }
      }
    }
  }

  cout << cnt << '\n';
  return 0;
}