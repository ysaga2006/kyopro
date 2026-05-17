#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, m, s;
  cin >> n >> m >> s;
  vector<ll> price(n);
  for (int i = 0; i < n; ++i) {
    cin >> price[i];
  }
  while (m--) {
    ll t, q;
    cin >> t >> q;
    t--;
    s += price[t] * q;
    s -= (price[t] * q) / 2;
  }
  cout << s << '\n';
  return 0;
}
