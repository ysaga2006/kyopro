#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, k; cin >> n >> k;
  vector<ll> a(n), b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];

  ll cnt = 0;
  rep(i, n) cnt += abs(a[i] - b[i]);

  if (cnt <= k && (k - cnt) % 2 == 0) cout << "Yes" << '\n';
  else cout << "No" << '\n';
  return 0;
}