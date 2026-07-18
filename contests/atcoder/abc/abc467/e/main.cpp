#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = (1LL << 60);
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m;
  cin >> n >> m;

  vector<ll> a(n), b(n - 1);

  rep(i, n) cin >> a[i];
  rep(i, n - 1) cin >> b[i];

  ll ans = INF;

  for (ll f = 0; f < m; f++) {
    vector<ll> c = a;

    c[0] += f;
    ll cnt = f;

    for (ll i = 0; i < n - 1; i++) {
      ll remainder = (c[i] + c[i + 1]) % m;
      ll add = (b[i] - remainder + m) % m;

      c[i + 1] += add;
      cnt += add;
    }

    ans = min(ans, cnt);
  }

  cout << ans << '\n';

  return 0;
}