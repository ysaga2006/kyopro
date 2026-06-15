#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, d; cin >> n >> d;
  ll ans = 0;

  vector<ll> v(1000002, 0);
  rep(i, n) {
    ll s, t; cin >> s >> t;
    if (s <= t - d) {
      v[s]++;
      v[t - d + 1]--;
    }
  }

  rep(i, 1000001) v[i + 1] += v[i];

  rep(i, 1000001) {
    ans += v[i] * (v[i] - 1) / 2;
  }

  cout << ans << '\n';
  return 0;
}
