#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct point {
  ll x, y;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll m;
  cin >> m;

  vector<point> wanted(m);
  for (ll i = 0; i < m; ++i)
    cin >> wanted[i].x >> wanted[i].y;

  ll n;
  cin >> n;

  vector<point> photo(n);
  set<pair<ll, ll>> st;
  for (ll i = 0; i < n; ++i) {
    cin >> photo[i].x >> photo[i].y;
    st.insert({photo[i].x, photo[i].y});
  }

  for (ll i = 0; i < n; ++i) {
    ll dx = photo[i].x - wanted[0].x;
    ll dy = photo[i].y - wanted[0].y;

    ll cnt = 0;
    for (ll j = 1; j < m; ++j) {
      if (st.contains({wanted[j].x + dx, wanted[j].y + dy})) cnt++;
    }
    
    if (cnt == m - 1) {
      cout << dx << " " << dy << '\n'; return 0;
    }
  }

  return 0;
}