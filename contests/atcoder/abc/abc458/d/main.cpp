#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll x, q; cin >> x >> q;

  multiset<ll> st;
  st.insert(x);

  auto mid = st.begin();

  while (q--) {
    ll a, b; cin >> a >> b;

    ll now = *mid, cnt = 0;
    if (a < now) cnt++;
    if (b < now) cnt++;

    st.insert(a); st.insert(b);

    if (cnt == 0) mid++;
    else if (cnt == 2) mid--;

    cout << *mid << '\n';
  }

  return 0;
}