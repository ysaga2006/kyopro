#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

const ll INF = 1000000000000000000;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n; cin >> n;
  vector<pair<ll, ll>> p(n);
  rep(i, n) cin >> p[i].first >> p[i].second;

  sort(p.begin(), p.end());

  ll jmin = INF;
  ll ans = 0;

  rep(i, n) {
    auto [x, y] = p[i];
    if (y < jmin) ans++, jmin = y;
  }

  cout << ans << '\n';
  return 0;
}
