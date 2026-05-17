#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n; cin >> n;

  vector<ll> a(n);
  for (ll i = 0; i < n; ++i) cin >> a[i];

  sort(a.begin(), a.end());

  ll q; cin >> q;
  while (q--) {
    ll b; cin >> b;
    auto ite = lower_bound(a.begin(), a.end(), b);
    if (ite != a.begin()) {
      cout << min(*ite - b, b - *(ite - 1)) << '\n'; 
    } else {
      cout << *ite - b << '\n';
    }
  }
  return 0;
}