#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, g, f;
  cin >> n >> g >> f;

  vector<pair<ll, ll>> station;
  for (ll i = 0; i < n; ++i) {
    ll p, r;
    cin >> p >> r;
    station.emplace_back(make_pair(p, r));
  }

  station.emplace_back(make_pair(g, 0));

  sort(station.begin(), station.end());

  priority_queue<ll> pq;

  ll pre = 0, fuel = f, ans = 0;
  for (const auto& [pos, add_fuel] : station) {
    fuel -= (pos - pre);
    while (fuel < 0) {
      if (pq.empty()) {
        cout << -1 << '\n';
        return 0;
      } else {
        fuel += pq.top();
        pq.pop();
        ans++;
      }
    }
    pre = pos;
    pq.push(add_fuel);
  }

  cout << ans << '\n';

  return 0;
}
