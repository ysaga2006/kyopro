#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll m, n, k; cin >> m >> n >> k;

  // [i][j]で(i, j)をもつ。(1-indexed)
  vector jungle(m + 1, vector<ll>(n + 1, 0));
  vector ocean(m + 1, vector<ll>(n + 1, 0));
  vector ice(m + 1, vector<ll>(n + 1, 0));

  // 入力
  for (ll i = 1; i < m + 1; ++i) for (ll j = 1; j < n + 1; ++j) {
    char x; cin >> x;
    if (x == 'J') jungle[i][j]++;
    if (x == 'O') ocean[i][j]++;
    if (x == 'I') ice[i][j]++;
  }

  // [i][j]で(0, 0)から(i, j)までに合計何マスかをもつ
  for (ll i = 0; i < m; ++i) for (ll j = 0; j < n + 1; ++j) {
    jungle[i + 1][j] += jungle[i][j];
    ocean[i + 1][j] += ocean[i][j];
    ice[i + 1][j] += ice[i][j];
  }

  for (ll i = 0; i < m + 1; ++i) for (ll j = 0; j < n; ++j) {
    jungle[i][j + 1] += jungle[i][j];
    ocean[i][j + 1] += ocean[i][j];
    ice[i][j + 1] += ice[i][j];
  }

  // クエリ処理
  for (ll i = 0; i < k; ++i) {
    ll a, b, c, d; cin >> a >> b >> c >> d;
    ll mori = jungle[c][d] - jungle[c][b - 1] - jungle[a - 1][d] + jungle[a - 1][b - 1];
    ll umi = ocean[c][d] - ocean[c][b - 1] - ocean[a - 1][d] + ocean[a - 1][b - 1];
    ll kori = ice[c][d] - ice[c][b - 1] - ice[a - 1][d] + ice[a - 1][b - 1];
    
    cout << mori << " " << umi << " " << kori << '\n';
  }

  return 0;
}