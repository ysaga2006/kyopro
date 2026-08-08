#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = (1LL << 60);
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, Q; cin >> n >> Q;
  vector<ll> p(n), q(n);
  rep(i, n) {
    cin >> p[i];
    p[i]--;
    q[p[i]] = i;
  }

  rep(qi, Q) {
    ll op; cin >> op;
    if (op == 1) {
      ll x, y; cin >> x >> y;
      x--; y--;

      ll i = p[x], j = p[y];

      p[x] = j, p[y] = i;
      q[i] = y, q[j] = x;
    } else {
      swap(p, q);
    }
  }

  rep(i, n) {
    cout << p[i] + 1 << '\n';
  }

  return 0;
}
