#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m, q;
  cin >> n >> m >> q;
  map<ll, set<ll>> mp;  // mp[i] = ページiが見れる人
  set<ll> st;           // 全部行ける人

  rep(qi, q) {
    ll op;
    cin >> op;
    if (op == 1) {
      ll x, y;
      cin >> x >> y;
      mp[y].insert(x);
    }
    if (op == 2) {
      ll x;
      cin >> x;
      st.insert(x);
    }
    if (op == 3) {
      ll x, y;
      cin >> x >> y;
      if (st.contains(x)) cout << "Yes" << '\n';
      else if (mp[y].contains(x)) cout << "Yes" << '\n';
      else cout << "No" << '\n';
    }
  }
  return 0;
}
