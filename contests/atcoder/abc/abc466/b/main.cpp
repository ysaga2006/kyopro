#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m;
  cin >> n >> m;

  vector<ll> ans(m, -1);
  rep(i, n) {
    ll c, s; cin >> c >> s;
    c--;
    if (ans[c] < s) ans[c] = s;
  }

  rep(i, m) cout << ans[i] << '\n';
  return 0;
}
