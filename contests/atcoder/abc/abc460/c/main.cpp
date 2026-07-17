#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m; cin >> n >> m;

  vector<ll> a(n), b(m);
  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  ll ans = 0, neta = 0;
  for (ll i = 0; i < n; ++i) {
    if (b[neta] <= 2 * a[i] && neta < m) {
      ans++; neta++;
    }
  }

  cout << ans << '\n';
  return 0;
}
