#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll a, b, c; cin >> a >> b >> c;
  ll m = gcd(a, (gcd(b, c)));

  cout << (a + b + c) / m - 3 << '\n';
  return 0;
}