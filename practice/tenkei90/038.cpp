#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  const ll INF = 1000000000000000000;

  ll a, b; cin >> a >> b;
  ll GCD = gcd(a, b);
  ll L = a / GCD;

  if (L > INF / b) cout << "Large" << '\n';
  else cout << L * b << '\n';

  return 0;
}