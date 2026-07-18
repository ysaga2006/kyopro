#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lll = __int128_t;
constexpr ll INF = (1LL << 60);
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  struct Point {
    ll x, y;
  };

  ll t; cin >> t;
  rep(ti, t) {
    vector<Point> p(4);
    rep(i, 4) cin >> p[i].x >> p[i].y;
    
    if (lll(p[0].x - p[1].x) * lll(p[3].y - p[2].y) != lll(p[0].y - p[1].y) * lll(p[3].x - p[2].x)) {
      cout << "Yes" << '\n';
      continue;
    }

    if (lll(p[1].x - p[0].x) * lll(p[3].x * p[3].x + p[3].y * p[3].y - p[2].x * p[2].x - p[2].y * p[2].y) == lll(p[3].x - p[2].x) * lll(p[1].x * p[1].x + p[1].y * p[1].y - p[0].x * p[0].x - p[0].y * p[0].y) && lll(p[1].y - p[0].y) * lll(p[3].x * p[3].x + p[3].y * p[3].y - p[2].x * p[2].x - p[2].y * p[2].y) == lll(p[3].y - p[2].y) * lll(p[1].x * p[1].x + p[1].y * p[1].y - p[0].x * p[0].x - p[0].y * p[0].y)) {
      cout << "Yes" << '\n';
    } else {
      cout << "No" << '\n';
    }
    
  }
  return 0;
}
