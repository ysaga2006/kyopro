#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 100000;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m; cin >> n >> m;

  vector<ll> dist(n); // iとi+1の距離
  for (ll i = 0; i < n - 1; ++i) cin >> dist[i];

  vector<ll> s(n + 1); // 0からiまでの距離
  s[0] = 0;
  for (ll i = 0; i < n; ++i) {
    s[i + 1] = (s[i] + dist[i]) % mod;
  }

  vector<ll> idou(m);
  for (ll i = 0; i < m; ++i) cin >> idou[i];

  ll now = 0, pre = 0, ans = 0;

  for (ll i = 0; i < m; ++i) { // nowまで移動
    now += idou[i];
    if (now > pre) {
      ans += (s[now] - s[pre] + mod) % mod;
    } else {
      ans += (s[pre] - s[now] + mod) % mod;
    }
    pre = now;
  }

  cout << ans % mod << '\n';

  return 0;
}