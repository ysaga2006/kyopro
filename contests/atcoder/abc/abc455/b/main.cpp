#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  ll h, w; cin >> h >> w;
  vector<string> v(h);
  for (ll i = 0; i < h; ++i) cin >> v[i];

  ll ans = 0;

  for (ll i = 0; i < h; ++i) for (ll j = i; j < h; ++j) for (ll k = 0; k < w; ++k) for (ll l = k; l < w; ++l) {
    bool ok = true;
    for (ll m = i; m <= j; ++m) for(ll n = k; n <= l; ++n) {
      if (v[m][n] != v[i + j - m][k + l - n]) ok = false;
    }
    if (ok == true) ans++;
  }
  
  cout << ans << '\n';
  return 0;
}
