#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n; cin >> n;

  vector<ll> a(n), b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  ll ans = 0;

  rep(i, n) {
    ans += abs(a[i] - b[i]);
  }

  cout << ans << '\n';
  return 0;
}