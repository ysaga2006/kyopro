#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, q; cin >> n >> q;
  ll x = 0, y = 0, cnt = 0;

  vector<pair<ll, ll>> move{};

  while (q--) {
    ll op; cin >> op;
    if (op == 1) {
      char c; cin >> c;
      if (c == 'R') x++;
      if (c == 'L') x--;
      if (c == 'U') y++;
      if (c == 'D') y--;
      move.push_back({x, y});
      cnt++;
    } else {
      ll p; cin >> p;
      if (cnt <= p) cout << p - cnt << " " << 0 << '\n';
      else cout << p + move[cnt - p - 1].first << " " << move[cnt - p - 1].second << '\n';
    }
  }

  return 0;
}