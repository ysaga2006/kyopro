#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n; cin >> n;
  vector v(n, vector<ll>{});
  rep(i, n) {
    ll k; cin >> k;
    rep(j, k) {
      ll a; cin >> a; --a;
      v[a].push_back(i);
    }
  }

  rep(i, n) {
    cout << v[i].size() << " ";
    for (auto& x : v[i]) cout << x + 1 << " ";
    cout << '\n';
  }
  return 0;
}
