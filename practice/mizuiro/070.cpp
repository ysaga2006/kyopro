#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  const ll mod = 1'000'000'007;

  ll m, n; cin >> m >> n;
  
  m %= mod;

  ll res = 1, a = m;
  
  while (n > 0) {
    if (n & 1) {
      res = res * a % mod;
    }
    a = a * a % mod;
    n >>= 1;
  }

  cout << res << '\n';
  return 0;
}