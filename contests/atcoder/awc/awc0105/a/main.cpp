#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll ans = 0;

  ll n, q; cin >> n >> q;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  string s; cin >> s;
  ll now = 0;
  rep(i, q) {
    if (s[i] == 'R') {
      now = (now + 1) % n;
    } else {
      now = (now - 1 + n) % n;
    }
    ans += a[now];
  }

  cout << ans << '\n';
  return 0;
}
