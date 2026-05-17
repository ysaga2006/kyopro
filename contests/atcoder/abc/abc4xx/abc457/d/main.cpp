#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const __int128_t INF = 1e30;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, k; cin >> n >> k;

  vector<ll> a(n + 1);
  for (ll i = 1; i <= n; ++i) cin >> a[i];

  auto hantei = [&](ll x) {
    __int128_t kaisu = 0;
    for (ll i = 1; i <= n; ++i) {
      if (a[i] >= x) continue;
      kaisu += (x - a[i] + i - 1) / i;
    }

    return kaisu <= k;
  };

  ll l = -1, r = INF;
  while (r - l > 1) {
    ll m = l + (r - l) / 2;

    if (hantei(m) == true) {
      l = m;
    } else {
      r = m;
    }
  }

  cout << l << '\n';

  return 0;
}
