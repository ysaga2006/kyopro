#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

const ll INF = 1000000000000000000;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, s; cin >> n >> s;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<ll> dp(s + 1, INF);
  // dp[i] = iを作るのに必要な最小枚数

  dp[0] = 0;

  for (auto& x : a) {
    for (ll i = )
  }

  return 0;
}
