#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<set<ll>> heihou(10); // 最高位がiの平方数2 * 10^18まで。 
  for (ll i = 0; i < 2000000000; ++i) {
    ll seki = i * i;
    string mozi = to_string(seki);
    heihou[mozi[0] - '0'].insert(seki);
  }

  ll t; cin >> t;
  while (t--) {
    ll c, d; cin >> c >> d; 
  }
  return 0;
}