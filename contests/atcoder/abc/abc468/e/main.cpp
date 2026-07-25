#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
constexpr ll INF = (1LL << 60);
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

using mint = atcoder::modint998244353;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n; cin >> n;
  vector<mint> a(n);
  rep(i, n) {
    ll x; cin >> x;
    a[i] = x;
  }

  vector<mint> cho(n + 5);
  rep(i, n) cho[i + 1] = cho[i] + mint(i + 1).inv();

  vector<mint> b(n + 5);
  b[0] = cho[n];
  rep(i, n) {
    b[i + 1] = b[i] - cho[i + 1] + cho[n - i - 1];
  }

  mint ans = 0;
  rep(i, n) ans += a[i] * b[i];

  cout << ans.val() << '\n';
  return 0;
}
