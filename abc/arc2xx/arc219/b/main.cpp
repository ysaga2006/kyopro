#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 998244353;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;

    vector<ll> p(n);
    for (ll i = 0; i < n; ++i)
      cin >> p[i];

    bool IOTA = true;

    for (ll i = 1; i <= n; ++i) {
      if (p[i - 1] == i)
        continue;
      else {
        cout << (n * (i - 1) - ((i - 1) * i / 2)) % MOD << '\n';
        IOTA = false;
        break;
      }
    }

    if (IOTA == true) {
      cout << (1 + n * (n - 1) - ((n - 1) * n / 2)) % MOD << '\n';
    } 
  }
  return 0;
}
