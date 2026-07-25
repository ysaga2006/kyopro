#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = (1LL << 60);
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n; cin >> n;
  vector<ll> p(n), q(n);

  rep(i, n) cin >> p[i];
  rep(i, n) cin >> q[i];

  ll ans = 0;

  vector<ll> r(n);
  iota(r.begin(), r.end(), 1);

  do {
    if (p < r && r < q) ans++;
  } while (next_permutation(r.begin(), r.end()));

  cout << ans << '\n';
  return 0;
}
