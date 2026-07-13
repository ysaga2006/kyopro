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
    ll n; cin >> n;

    auto f = [&](ll x) {
      return x * x >= 4 * n;
    };

    ll ok = INF, ng = -1;
    while (ok - ng > 1) {
      ll mid = (ok + ng) / 2;
      if (f(mid) == true) {
        ok = mid;
      } else {
        ng = mid;
      }
    }

    cout << 2 * n - ok << '\n';
  }
  return 0;
}
