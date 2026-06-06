#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m; cin >> n >> m;

  vector g(n, priority_queue<ll, vector<ll>, greater<ll>>{});

  rep(i, m) {
    ll a, b; cin >> a >> b;
    --a; --b;
    g[a].push(b);
    g[b].push(a);
  }

  ll ans = 0;

  rep(i, n) {
    if (g[i].empty()) continue;
    ll first = g[i].top();
    g[i].pop();

    if (g[i].empty() && first < i) {
      ans++; continue;
    }

    ll second = g[i].top();

    if (first < i && i <= second) ans++;
  }

  cout << ans << '\n';
  return 0;
}