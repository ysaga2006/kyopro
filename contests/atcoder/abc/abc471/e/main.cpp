#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
constexpr ll INF = (1LL << 60);
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

using mint = atcoder::modint998244353;

const int MAX = 510000;
mint fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    const int MOD = mint::mod();
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i;
        inv[i] = MOD - inv[MOD%i] * (MOD / i);
        finv[i] = finv[i - 1] * inv[i];
    }
}

mint COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * finv[k] * finv[n - k];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  COMinit();

  ll n, k; cin >> n >> k;

  mint total = 0, htotal = 0;

  rep(i, n) {
    ll x; cin >> x;
    total += x;
    htotal += x * x;
  }

  mint ans = COM(n - 1, k - 1) * htotal + COM(n - 2, k - 2) * (total * total - htotal);
  cout << ans.val() << '\n';;
  return 0;
}
