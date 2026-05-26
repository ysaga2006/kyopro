#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll INF = 1000000000000000000;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, a, b, c; cin >> n >> a >> b >> c;

  ll ans = INF;

  for (ll i = 0; i <= 9999; ++i) {
    for (ll j = 0; j <= 9999 - i; ++j) {
      ll val = n - a * i - b * j;
      if (val < 0) continue;
      if (val % c == 0) ans = min(ans, i + j + val / c);
    }
  }

  cout << ans << '\n';
  return 0;
}