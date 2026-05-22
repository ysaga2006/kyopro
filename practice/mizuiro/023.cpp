#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m;
  cin >> n >> m;
  ll ans = 0;

  vector<ll> p(n);
  for (ll i = 0; i < n; ++i)
    cin >> p[i];
  
  for (ll i = 0; i < 3; ++i) p.push_back(0);

  set<ll> st;  // 2回投げて得られる点数の和の集合
  for (ll i = 0; i < n + 3; ++i)
    for (ll j = i; j < n + 3; ++j)
      st.insert(p[i] + p[j]);

  // st[i] + st[j] <= M なる最大の st[i] + st[j] を求める
  // st[i] <= M - st[j] を満たす最大の st[i] を二分探索で

  for (auto& one : st) {
    auto it = st.upper_bound(m - one);
    if (it == st.begin())
      continue;
    --it;

    ans = max(ans, *it + one);
  }

  cout << ans << '\n';
  return 0;
}