#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = (1LL << 60);
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, q; cin >> n >> q;

  vector<ll> a(n, 0);

  ll total = 0;
  rep(qi, q) {
    ll op; cin >> op;
    if (op == 1) {
      ll x; cin >> x; x--;
      total = total ^ a[x] ^ (a[x] + 1);
    } else {
      
    }
  }

  return 0;
}
