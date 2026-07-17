#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll h, w, d; cin >> h >> w >> d;

  vector<string> g(h);
  rep(i, h) cin >> g[i];

  ll ans = 0;
  rep(i1, h) rep(j1, w) rep(i2, h) rep(j2, w) {
    if (g[i1][j1] == '#' || g[i2][j2] == '#') continue;
    ll cnt = 0; 
    vector wet(h, vector<bool>(w, false));
    wet[i1][j1] = true;
    wet[i2][j2] = true;
    
    rep(i, h) rep(j, w) {
      if (g[i][j] == '#') continue;
      if (abs(i - i1) + abs(j - j1) <= d || abs(i - i2) + abs(j - j2) <= d) {
        wet[i][j] = true;
      }
    }

    rep(i, h) rep(j, w) {
      cnt += (wet[i][j]);
    }

    ans = max(ans, cnt);
  }

  cout << ans << '\n';
  return 0;
}
