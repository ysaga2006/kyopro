#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll ans = 0;
  ll d, n, m; cin >> d >> n >> m;

  vector<ll> mise(2 * n);
  mise[0] = 0;
  for (ll i = 1; i < n; ++i) cin >> mise[i];
  for (ll i = 0; i < n; ++i) mise[n + i] = mise[i] + d; 

  sort(mise.begin(), mise.end());

  for (ll i = 0; i < m; ++i) {
    ll k; cin >> k;
    auto ite = lower_bound(mise.begin(), mise.end(), k);
    if (ite == mise.begin()) {
      ans += abs(*ite - k);
    } else {
      ans += min(abs(*ite - k), abs(*(ite - 1) - k));
    }
  }

  cout << ans << '\n';
  return 0;
}