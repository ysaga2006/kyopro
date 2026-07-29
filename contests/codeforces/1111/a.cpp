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
    ll sum = 0;
    rep(i, n) {
      ll x; cin >> x;
      sum += x;
    }    
    if (sum % 4 == 0) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
  return 0;
}
