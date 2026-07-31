#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = (1LL << 60);
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, q; cin >> n >> q;
  // 受付に呼ばれる　受付に行く
  set<ll> st;
  rep(qi, q) {
    ll op; cin >> op;
    if (op == 1) {

    } else if (op == 2) {
      ll x; cin >> x;
    } else {

    }
  }

  return 0;
}
