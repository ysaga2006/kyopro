#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n; cin >> n;

  vector<ll> a(n - 1), b(n - 1);
  rep(i, n - 1) cin >> a[i] >> b[i], a[i]--, b[i]--;

  vector g(n, vector<ll>{}); // 隣接リストを持つ
  rep(i, n - 1) g[a[i]].push_back(b[i]), g[b[i]].push_back(a[i]);

  vector<ll> col(n, -1);

  auto dfs = [&](auto dfs, ll v, ll iro) -> void { // vをiro(0, 1)で塗っていく
    col[v] = iro;
    for (auto& nv : g[v]) {
      if (col[nv] != -1) continue;
      dfs(dfs, nv, 1 - iro);
      // cout << "dfs(dfs, " << nv << ", " << 1 - iro << ")" << '\n';
    }
  };

  dfs(dfs, 0, 0);

  // for (ll i = 0; i < n; ++i) {
  //   cout << col[i] << " ";
  // }
  // cout << '\n';

  ll cnt = 0; // 0で塗られている頂点の数
  for (ll i = 0; i < n; ++i) {
    if (col[i] == 0) cnt++;
  }

  ll kazu = 0;
  if (2 * cnt > n) {
    for (ll i = 0; i < n; ++i) {
      if (col[i] == 0) cout << i + 1 << " ", kazu++;
      if (kazu == n / 2) break;
    }
    cout << '\n';
  } else {
    for (ll i = 0; i < n; ++i) {
      if (col[i] == 1) cout << i + 1 << " ", kazu++;
      if (kazu == n / 2) break;
    }
    cout << '\n';
  }
  return 0;
}