#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n; cin >> n;

  ll fin;
  vector<ll> a(105, 0);
  rep(i, n) {
    ll t, v; cin >> t >> v;
    t--;
    a[t] = v;
    if (i == n - 1) fin = t + 1;
  }

  ll ans = 0;
  rep(i, fin) {
    ans = max(ans - 1, 0ll);
    ans += a[i];

  }

  cout << ans << '\n';
  return 0;
}