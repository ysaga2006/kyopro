#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n; cin >> n;
  
  vector<ll> one(n + 1), two(n + 1);
  for (ll i = 0; i < n; ++i) {
    ll c, p; cin >> c >> p;
    if (c == 1) {
      one[i + 1] += p;
    } else {
      two[i + 1] += p;
    }
  }

  for (ll i = 0; i < n; ++i) {
    one[i + 1] += one[i];
    two[i + 1] += two[i];
  }

  ll q; cin >> q;
  while (q--) {
    ll l, r; cin >> l >> r;
    cout << one[r] - one[l - 1] << " " << two[r] - two[l - 1] << '\n';
  }
  return 0;
}