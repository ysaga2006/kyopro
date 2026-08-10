#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll k;
  cin >> k;

  ll ans = 0;
  for (ll i = 1; i * i * i <= k; i++) {
    if (k % i != 0) continue;
    for (ll j = i; j * j <= (k / i) + 5; j++) {
      if ((k / i) % j != 0) continue;
      if ((k / i / j) < j) continue;
      ans++;
    }
  }

  cout << ans << '\n';
  return 0;
}