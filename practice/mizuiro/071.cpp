#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1'000'000'007;

// powmod
ll powmod(ll a, ll n, ll m) {
  ll res = 1;
  a %= m;
  while (n > 0) {
    if (n & 1) {
      res = res * a % m;
    }
    a = a * a % m;
    n >>= 1;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, q;
  cin >> n >> q;

  vector<ll> a(n);
  for (ll i = 0; i < n; ++i) cin >> a[i];

  vector<ll> route(q + 2);
  route[0] = 0; route[q + 1] = 0;
  for (ll i = 1; i < q + 1; ++i) {
    cin >> route[i];
    route[i]--;
  }

  vector<ll> path(n - 1); // path[i]は街iから街i + 1までの距離
  for (ll i = 0; i < n - 1; ++i) {
    path[i] = powmod(a[i], a[i + 1], mod);
  }

  // dist[i]は街0から街iまでの距離
  // 街lから街rまでの距離は、dist[r] - dist[l - 1]
  vector<ll> dist(n);
  dist[0] = 0; dist[1] = 0;
  for (ll i = 0; i < n - 1; ++i) {
    dist[i + 1] = (dist[i] + path[i]) % mod;
  }

  ll ans = 0;
  for (ll i = 0; i < q + 1; ++i) { // route[i]からroute[i + 1]までの距離を加算
    ll from = route[i], to = route[i + 1];
    if (from > to) swap(from, to); 
    ans += (dist[to] - dist[from] + mod) % mod;
    cout << ans << '\n';
  }

  cout << ans % mod << '\n';

  return 0;
}