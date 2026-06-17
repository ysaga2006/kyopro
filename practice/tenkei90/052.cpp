#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

const ll MOD = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n; cin >> n;

  vector a(n, vector<ll>(6));
  rep(i, n) rep(j, 6) cin >> a[i][j];

  ll ans = 1;
  rep(i, n) {
    ll sum = 0;
    rep(j, 6) sum += a[i][j];
    ans *= sum;
    ans %= MOD;
  }

  cout << ans << '\n';
  return 0;
}