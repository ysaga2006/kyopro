#include <bits/stdc++.h>
using namespace std;
namespace rng = std::ranges;
namespace vw = std::views;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n; cin >> n;
  string s; cin >> s;

  ll ans = 0;

  for (ll i = 0; i < 10; ++i) for (ll j = 0; j < 10; ++j) for (ll k = 0; k < 10; ++k) {
    ll cnt = 0;
    for (char moji : s) {
      if (cnt == 0 && moji == char(i + '0')) cnt++;
      else if (cnt == 1 && moji == char(j + '0')) cnt++;
      else if (cnt == 2 && moji == char(k + '0')) cnt++;
    }
    if (cnt == 3) ans++;
  }
  
  cout << ans << '\n';
  return 0;
}