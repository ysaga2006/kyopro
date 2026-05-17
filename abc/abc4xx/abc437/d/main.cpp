#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 998244353;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m; cin >> n >> m;
  
  vector<ll> a(n);
  for (ll i = 0; i < n; ++i) cin >> a[i];

  vector<ll> b(m);
  for (ll i = 0; i < m; ++i) cin >> b[i];

  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());

  vector<ll> s(n + 1, 0);
  for (ll i = 0; i < n; ++i) s[i + 1] = s[i] + a[i]; 

  ll ans = 0;
  for (ll i = 0; i < m; ++i) {
    ll k = upper_bound(a.begin(), a.end(), b[i], greater<ll>()) - a.begin() - 1;

    ans += (s[k + 1] - s[0]) % MOD;
    ans = (ans + MOD - ((s[n] - s[k + 1]) % MOD)) % MOD;
    ans = (ans + MOD - ((b[i] * (k + 1)) % MOD)) % MOD;
    ans += (b[i] * (n - 1 - k)) % MOD;
  }

  cout << ans % MOD << '\n';

  return 0;
}