#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

using S = ll;
using F = ll;

S op(S a, S b) {
  return max(a, b);
}

S e() {
  return 0;
}

S mapping(F f, S x) {
  if (f == -1) return x;
  return f;
}

F composition(F f, F g) {
  if (f == -1) return g;
  return f;
  
}

F id() {
  return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll w, n; cin >> w >> n;

  lazy_segtree<S, op, e, F, mapping, composition, id> seg(n);

  rep(i, n) {
    ll l, r; cin >> l >> r;
    
  }
  return 0;
}