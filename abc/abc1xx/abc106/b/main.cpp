#include <bits/stdc++.h>
using namespace std;
namespace rng = std::ranges;
namespace vw  = std::views;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  ll n; cin >> n;

  ll ans = 0;

  for (ll i = 1; i <= n; ++i) {
    ll cnt = 0;
    if (i % 2 == 1) {
      for (ll j = 1; j <= i; ++j) {
        if (i % j == 0) cnt++;
      }
    }
    if (cnt == 8) ans++;
  }

  cout << ans << '\n';

  return 0;
}
