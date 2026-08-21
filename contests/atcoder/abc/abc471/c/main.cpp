#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = (1LL << 60);
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  sort(a.begin(), a.end());

  ll r = lower_bound(a.begin(), a.end(), 0ll) - a.begin(), l = r - 1;
  ll ans = 0, now = 0;

  while (l >= 0 && r < n) {
    if (abs(now - a[l]) > abs(now - a[r])) {
      ans += abs(now - a[r]);
      now = a[r];
      r++;
    } else {
      ans += abs(now - a[l]);
      now = a[l];
      l++;
    }
  }

  if (l < 0) {
    ans += a[n - 1] + now;
  } else {
    ans += now - a[0];
  }

  cout << ans << '\n';
  return 0;
}
