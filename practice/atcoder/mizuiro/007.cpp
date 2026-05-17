#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct point {
  ll x, y;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n; cin >> n;

  vector<point> v(n);
  set<pair<ll, ll>> st;

  for (ll i = 0; i < n; ++i) {
    cin >> v[i].x >> v[i].y;
    st.insert({v[i].x, v[i].y});
  }

  ll ans = 0;
  for (ll i = 0; i < n; ++i) for (ll j = i + 1; j < n; ++j) {
    auto [a, b] = v[i];
    auto [c, d] = v[j];
    if (a > c) {
      swap(a, c); swap(b, d);
    }
    ll dx = c - a;
    ll dy = d - b;
    if (d <= b) {
      if (st.contains({a - dy, b + dx}) && st.contains({c - dy, d + dx})) ans = max(ans, (dx * dx) + (dy * dy));
    } else {
      if (st.contains({a + dy, b - dx}) && st.contains({c + dy, d - dx})) ans = max(ans, (dx * dx) + (dy * dy));
    }
  }

  cout << ans << '\n';
  return 0;
}