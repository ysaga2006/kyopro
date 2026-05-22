#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n; cin >> n;

  vector<ll> fib(50);
  fib[0] = 1; fib[1] = 1;

  for (ll i = 0; i < 48; ++i) {
    fib[i + 2] = fib[i + 1] + fib[i];
  }

  cout << fib[n] << '\n';
  
  return 0;
}