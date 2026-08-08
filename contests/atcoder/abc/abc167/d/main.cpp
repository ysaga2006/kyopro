#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = (1LL << 60);
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  const ll LOG = 60;
  
  ll n, k; cin >> n >> k;
  
  vector jump(LOG, vector<ll>(n));
  rep(i, n) {
    ll a; cin >> a;
    a--;
    jump[0][i] = a;
  }

  rep(i, LOG - 1) {
    rep(j, n) {
      jump[i + 1][j] = jump[i][jump[i][j]];
    }
  }

  ll ans = 0;
  rep(i, LOG) {
    if (k & (1 << i)) ans = jump[i][ans];
  }

  ans++;
  cout << ans << '\n';
  return 0;
}
