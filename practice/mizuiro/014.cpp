#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll ans = INF;
  ll n, k; cin >> n >> k;

  vector<ll> a(n);
  for (ll i = 0; i < n; ++i) cin >> a[i];

  for (ll bit = 0; bit < (1 << (n - 1)); ++bit) {
    ll cost = 0, now = a[0];
    if (popcount(unsigned(bit)) != k - 1) continue;
    for (ll i = 0; i < n - 1; ++i) {
      if (bit & (1 << i)) {
        if (now < a[i + 1]) now = a[i + 1];
        else {
          cost += now + 1 - a[i + 1];
          now++;
        }
      } else {
        now = max(now, a[i + 1]);
      }
    }

    ans = min(ans, cost);
  }

  cout << ans << '\n';
  return 0;
}