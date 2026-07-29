#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = (1LL << 60);
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t; cin >> t;
  rep(ti, t) {
    ll n; cin >> n;

    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    // aから和が奇数になるような長さkの部分列を持ってくる
    // それらを反転する
    // aをbにするのに最小で何階の操作が必要か
  }
  return 0;
}
