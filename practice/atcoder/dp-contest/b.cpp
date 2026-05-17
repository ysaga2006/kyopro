#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, k;
  cin >> n >> k;

  vector<ll> h(n);
  for (ll i = 0; i < n; ++i)
    cin >> h[i];

  // Nまでの最小コストをdp[N]でもつ
  vector<ll> dp(n);
  dp[0] = 0;

  for (ll i = 1; i < n; ++i) {  // dp[i]を考察する

    ll mincost = 100100100100;
    for (ll j = 1; j <= k; ++j) {
      if (i - j >= 0) {
        mincost = min(mincost, dp[i - j] + abs(h[i - j] - h[i]));
      }  // j段前からジャンプしてi段目に来た時
    }

    dp[i] = mincost;
  }

  cout << dp[n - 1] << '\n';
  return 0;
}