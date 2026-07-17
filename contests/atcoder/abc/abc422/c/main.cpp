#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

const ll INF = 10000000000;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t; cin >> t;
  rep(ti, t) {
    ll a, b, c; cin >> a >> b >> c;
    auto f = [&](ll x) -> bool {
      if (a < x || c < x) return false;
      else if ((a - x) + (c - x) + b < x) return false;
      return true;
    };

    ll ok = 0, ng = a + b + c;
    while (ng - ok > 1) {
      ll mid = (ok + ng) / 2;
      if (f(mid) == true) {
        ok = mid;
      } else {
        ng = mid;
      }
    }

    cout << ok << '\n';
  }
  return 0;
}