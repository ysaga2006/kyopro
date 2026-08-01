#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = (1LL << 60);
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll q; cin >> q;

  set<ll> st;

  rep(qi, q) {
    ll op; cin >> op;
    if (op == 1) {
      ll x; cin >> x;
      st.insert(x);
    } else if (op == 2) {
      ll x; cin >> x;
      st.erase(x);
    } else {
      ll x; cin >> x;
      auto it = lower_bound(st.begin(), st.end(), x);
      if (it == st.end()) cout << -1 << '\n';
      else cout << *it << '\n';
    }
  }
  return 0;
}