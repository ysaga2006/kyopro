#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = (1LL << 60);
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll q, v; cin >> q >> v;

  multiset<ll> st;

  rep(qi, q) {
    ll op; cin >> op;
    if (op == 1) {
      ll t, w; cin >> t >> w;
      st.insert(w - t);
    } else {
      ll t; cin >> t;

      if (st.empty()) {
        cout << -1 << '\n';
        continue;
      }

      ll big = *st.rbegin();

      cout << min(v, big + t) << '\n';
      st.erase(prev(st.end()));
    }
  }
  return 0;
}
