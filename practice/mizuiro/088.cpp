#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n; cin >> n;

  vector<pair<ll, ll>> v;

  for (ll i = 1; i < n + 1; ++i) {
    ll stone; cin >> stone;

    if (i % 2 == 0) {
      if (stone == v.back().first) v.back().second++;
      else {
        ll pre = v.back().second;
        v.pop_back();
        if (!v.empty()) v.back().second += pre + 1;
        else v.push_back({stone, pre + 1});
      }
    } else {
      if (!v.empty() && stone == v.back().first) v.back().second++;
      else v.push_back({stone, 1});
    }
  }

  ll ans = 0;
  for (auto x : v) {
    if (x.first == 0) ans += x.second;
  }

  cout << ans << '\n';
  return 0;
}