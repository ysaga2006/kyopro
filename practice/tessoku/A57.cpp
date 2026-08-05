#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = (1LL << 60);
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

const ll LOG = 32;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, q; cin >> n >> q;

  vector jump(LOG, vector<ll>(n));
  rep(i, n) {
    cin >> jump[0][i];
    jump[0][i]--;
  }

  rep(i, LOG - 1) {
    rep(j, n) {
      jump[i + 1][j] = jump[i][jump[i][j]];
    }
  }

  rep(qi, q) {
    ll x, y; cin >> x >> y;
    x--;
    
    rep(i, LOG) {
      if (y & (1 << i)) {
        x = jump[i][x];
      }
    }

    x++;
    cout << x  << '\n';
  }
  return 0;
}