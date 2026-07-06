#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll h, w;
  cin >> h >> w;

  vector table(h, vector<ll>(w));
  rep(i, h) rep(j, w) cin >> table[i][j];

  vector goal(h, vector<ll>(w));
  rep(i, h) rep(j, w) cin >> table[i][j];

  ll ans = 0;
  rep(i, h - 1) rep(j, w - 1) {
    ll val = goal[i][j] - table[i][j];
    table[i][j] += val;
    table[i][j + 1] += val;
    table[i + 1][j] += val;
    table[i + 1][j + 1] += val;

    ans += abs(val);
  }

  if (table == goal) {
    cout << ans << '\n';
  } else {
    cout << "No" << '\n';
  }
  return 0;
}