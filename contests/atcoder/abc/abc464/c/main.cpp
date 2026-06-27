#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m;
  cin >> n >> m;

  vector<ll> color(n, 0);

  vector change(m, vector<pair<ll, ll>>{});
  rep(i, n) {
    ll a, d, b;
    cin >> a >> d >> b;
    a--;
    b--;
    d--;
    color[a]++;
    change[d].push_back({a, b});
  }

  ll ans = 0;
  rep(i, n) ans += (color[i] > 0);

  rep(i, m) {
    for (auto [del, add] : change[i]) {
      if (color[add] == 0) ans++;
      color[add]++;

      color[del]--;
      if (color[del] == 0) ans--;
    }

    cout << ans << '\n';
  }

  return 0;
}
