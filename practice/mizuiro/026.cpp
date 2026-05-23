#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, q; cin >> n >> q;

  vector<ll> ans(n);
  
  vector g(n, vector<ll>{});
  for (ll i = 0; i < n - 1; ++i) {
    ll a, b; cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  while (q--) {
    ll p, x; cin >> p >> x;
    ans[p] += x;   
  }

  auto dfs = [&](auto dfs, ll v) -> void { // vの子にvのカウンターの値を足す（imosの累積和の部分） 
    for (auto& son : g[v]) {
      ans[son] += ans[v];
    } 
  };

  dfs(dfs, 0);

  for (ll i = 0; i < n; ++i) cout << ans[i] << " ";
  cout << '\n';

  return 0;
}