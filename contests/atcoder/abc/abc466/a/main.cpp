#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  bool ok = true;
  ll n; cin >> n;
  rep(i, n) {
    ll x; cin >> x;
    if (x >= 0) ok = false;
  }

  cout << (ok ? "Yes" : "No") << '\n';
  return 0;
}
