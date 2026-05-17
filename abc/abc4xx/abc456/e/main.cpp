#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  ll t; cin >> t;
  while (t--) {
    ll n, m; cin >> n >> m;

    vector list(n, vector<ll>{}); // iから訪問できるところをもつ

    for (ll i = 0; i < n; ++i) list[i].push_back(i);

    for (ll i = 0; i < m; ++i) {
      ll u, v; cin >> u >> v; u--; v--;
      list[u].push_back(v); 
      list[v].push_back(u);
    }

    ll w; cin >> w;

    vector<string> yasumi(n);
    for (ll i = 0; i < n; ++i) cin >> yasumi[i];

    for (ll i = 0; i < w; ++i) {
      for (auto place : yasumi[i]) {
        for (auto nextplace : list[place]) {
          if (week[i + 1].contains(nextplace)) 
        }
      }
    }
  }
  return 0;
}
