#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

const ll INF = 1000000000000000;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t;
  cin >> t;

  rep(ti, t) {
    ll n;
    string s;
    cin >> n >> s;

    vector<ll> x(n), y(n - 1);
    rep(i, n) cin >> x[i];
    rep(i, n - 1) cin >> y[i];

    vector dp(n, vector<ll>(2, -INF));

    rep(i, 2) dp[0][i] = - ((i == (s[0] == 'R')) ? 0 : x[0]);

    rep(i, n - 1) rep(pre, 2) rep(now, 2) {
      ll dec = (now == (s[i + 1] == 'R')) ? 0 : x[i + 1];
      ll add = (pre == 1 && now == 0) ? y[i] : 0;

      dp[i + 1][now] = max(dp[i + 1][now], dp[i][pre] - dec + add);
    }

    cout << max(dp[n - 1][0], dp[n - 1][1]) << '\n';
  }

  return 0;
}
