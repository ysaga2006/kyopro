#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n; cin >> n;

  vector v(1002, vector<ll>(1002, 0));

  rep(i, n) { // (a, b)が左下、(c, d)が右上
    ll a, b, c, d; cin >> a >> b >> c >> d;
    v[a][b]++;
    v[c][d]++;
    v[a][d]--;
    v[c][b]--;
  }

  rep(i, 1001) rep(j, 1002) v[i + 1][j] += v[i][j];
  rep(i, 1002) rep(j, 1001) v[i][j + 1] += v[i][j];

  vector<ll> ans(n + 1);
  rep(i, 1001) rep(j, 1001) ans[v[i][j]]++;

  rep(i, n) cout << ans[i + 1] << '\n';
  
  return 0;
}