#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = (1LL << 60);
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, k; cin >> n >> k;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll sum = 0;
  rep(i, k) sum += a[i];

  ll ans = sum;
  for (ll i = 1; i <= n - 1 - k + 1; i++) {
    sum = sum - a[i - 1] + a[i + k - 1];
    ans = min(ans, sum);
  } 

  cout << ans << '\n';
  return 0;
}
