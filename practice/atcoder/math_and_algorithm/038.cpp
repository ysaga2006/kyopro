#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = (1LL << 60);
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, q; cin >> n >> q;
  vector<ll> a(n + 1);
  rep(i, n) cin >> a[i + 1];

  rep(i, n) a[i + 1] += a[i]; 

  rep(qi, q) {
    ll l, r; cin >> l >> r;
    l--; r--;
    cout << a[r + 1] - a[l] << '\n';
  }
  return 0;
}