#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, k; cin >> n >> k;
  
  vector<ll> a(n);
  for (ll i = 0; i < n; ++i) cin >> a[i];

  sort(a.begin(), a.end());

  // for (auto x : a) cout << x << " ";
  // cout << '\n';
  
  vector<ll> b;
  b.push_back(a[0]);

  for (ll i = 0; i < n - 1; ++i) {
    if (a[i + 1] != a[i]) {
      b.push_back(a[i + 1]);
    } else {
      b.back() += a[i + 1];
    }
  }

  sort(b.begin(), b.end());

  ll ans = 0;
  for (ll i = 0; i < ll(b.size()) - k; ++i) {
    ans += b[i];
  }
  
  // for (auto x : b) cout << x << " ";
  // cout << '\n';
  
  cout << ans << '\n';
  return 0;
}
