#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll ans = 0;

  ll n, m;
  cin >> n >> m;

  vector<pair<ll, ll>> q(m);
  rep(i, m) {
    cin >> q[i].first >> q[i].second;
    q[i].first--; q[i].second--;
  }

  vector<bool> gyo(n, false), retu(n, false);

  for (ll i = m - 1; i >= 0; i--) {
    auto [r, c] = q[i];

    if (!gyo[r] && !retu[c]) ans++;

    gyo[r] = true, retu[c] = true;
  }

  cout << ans << '\n';

  return 0;
}