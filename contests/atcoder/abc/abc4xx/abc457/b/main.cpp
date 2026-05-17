#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  ll n; cin >> n;

  vector a(n, vector<ll>{});

  for (ll i = 0; i < n; ++i) {
    ll l; cin >> l;
    for (ll j = 0; j < l; ++j) {
      ll x; cin >> x;
      a[i].push_back(x);
    }
  }

  ll x, y; cin >> x >> y;
  x--; y--;

  cout << a[x][y] << '\n';
  return 0;
}
