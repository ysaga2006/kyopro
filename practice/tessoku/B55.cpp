#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = (1LL << 60);
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll q;
  cin >> q;

  set<ll> st;

  rep(qi, q) {
    ll op;
    cin >> op;
    if (op == 1) {
      ll x;
      cin >> x;
      st.insert(x);
    } else {
      ll x;
      cin >> x;
      if (st.empty()) cout << -1 << '\n';
      else {
        auto it = st.lower_bound(x);
        if (it == st.end()) it--, cout << abs(x - *it) << '\n';
        else if (it == st.begin()) cout << abs(x - *it) << '\n';
        else {
          ll val = *it;
          it--;
          cout << (min(abs(x - *it), abs(x - val))) << '\n';
        }
      }
    }
  }
  return 0;
}