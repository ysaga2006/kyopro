#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t; cin >> t;
  rep(ti, t) {
    ll ans = 0;

    ll x, y, k;
    cin >> x >> y >> k;

    while (x != y) {
      if (x > y) x /= k;
      else y /= k;
      ans++;
    }

    cout << ans << '\n';
  } 
  return 0;
}
