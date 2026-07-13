#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t; cin >> t;
  rep(ti, t) {
    ll k; cin >> k;
    rep(i, 100) {
      if (to_string((i + 1) * k).contains("00")) {
        cout << (i + 1) * k << '\n';
        break;
      }
    }
  }
  return 0;
}
