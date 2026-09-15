#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = (1LL << 60);
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n; cin >> n;
  vector<ll> a(105);

  rep(i, n) {
    ll x; cin >> x;
    a[x]++;
  }

  ll ans = 0;

  rep(i, 105) {
    if (a[i] % 2 == 1) {
      ans += i;
    }
  }

  cout << ans << '\n';
  return 0;
}
