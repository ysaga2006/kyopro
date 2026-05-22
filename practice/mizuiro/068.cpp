#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n; cin >> n;

  cout << n << ":";

  for (ll mod = 2; mod * mod <= n;) {
    if (n % mod == 0) {
      n /= mod;
      cout << " " << mod;
    } else {
      mod++;
    }
  }

  if (n > 1) {
    cout << " " << n;
  }

  cout << '\n';

  return 0;
}