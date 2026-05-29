#include <bits/stdc++.h>
#include <atcoder/scc>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m; cin >> n >> m;

  scc_graph g(n); // 相互ならmergeする

  while (m--) {
    ll a, b; cin >> a >> b;
    a--; b--;
    g.add_edge(a, b);
  }

  ll ans = 0;
  auto st = g.scc();
  for (auto& x : st) {
    ll k = x.size();
    ans += k * (k - 1) / 2;
  }

  cout << ans << '\n';

  return 0;
}