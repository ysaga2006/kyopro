#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = (1LL << 60);
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

vector<pair<ll, ll> > prime_factorize(ll N) {
  vector<pair<ll, ll> > res;
  for (ll a = 2; a * a <= N; ++a) {
    if (N % a != 0) continue;
    ll ex = 0;  // 指数

    // 割れる限り割り続ける
    while (N % a == 0) {
      ++ex;
      N /= a;
    }

    // その結果を push
    res.push_back({a, ex});
  }

  // 最後に残った数について
  if (N != 1) res.push_back({N, 1});
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;

  const auto& res = prime_factorize(n);

  ll cnt = 0;
  for (auto p : res) cnt+= p.second;

  cout << cnt << '\n';

  ll ans = 0, val = 1;
  while (val * 2 < cnt) {
    val *= 2;
    ans++;
  }

  cout << ans + 1 << '\n';

  return 0;
}