#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, q; cin >> n >> q;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll huben = 0;
  rep(i, n - 1) huben += abs(a[i] - a[i + 1]); 

  while (q--) {
    ll l, r, v; cin >> l >> r >> v;
    
  }
  return 0;
}