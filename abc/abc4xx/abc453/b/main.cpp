#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t, x;
  cin >> t >> x;
  ll pre;
  cin >> pre;
  cout << 0 << " " << pre << '\n';
  for (ll i = 1; i <= t; ++i) {
    ll a; 
    cin >> a;
    if (abs(a - pre) >= x) {
      cout << i << " " << a << '\n';
      pre = a;
    }
  }
  return 0;
}
