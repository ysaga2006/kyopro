#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;

  vector<ll> l(n);
  for (ll i = 0; i < n; ++i) cin >> l[i];

  ll ans = -1;
  for (ll bit = 0; bit < (1 << n); ++bit) {
    double now = 0.5, pre = 0.5;
    ll cnt = 0;
    for (ll i = 0; i < n; ++i) {
      if (bit & (1 << i)) {
        now += l[i];
      } else {
        now -= l[i];
      }
      if (pre * now < 0) cnt++;
        pre = now;
    }
    ans = max(ans, cnt);
  }
  
  cout << ans << '\n';
  return 0;
}

  // ll ans = 0;
  // double now = 0.5;
  // while (n--) {
  //   ll l;
  //   cin >> l;
  //   if (now > 0) {
  //     now -= l;
  //     if (now < 0) ans++;
  //   } else {
  //     now += l;
  //     if (now > 0) ans++;
  //   }
  // }
  // cout << ans << '\n';