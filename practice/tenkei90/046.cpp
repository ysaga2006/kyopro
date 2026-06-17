#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n; cin >> n;
  vector<ll> a(46), b(46), c(46); // a, b, cを46で割ったあまりで仕分ける

  rep(i, 3) {
    rep(j, n) {
      ll x; cin >> x;
      if (i == 0) a[x % 46]++;
      else if (i == 1) b[x % 46]++;
      else if (i == 2) c[x % 46]++;
    }
  }

  ll ans = 0;
  rep(i, 46) rep(j, 46) rep(k, 46) {
    if ((i + j + k) % 46 == 0) ans += a[i] * b[j] * c[k];
  }

  cout << ans << '\n';

  return 0;
}