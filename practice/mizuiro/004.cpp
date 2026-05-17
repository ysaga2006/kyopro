#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m; cin >> n >> m;

  ll ans = 0;

  vector score(n, vector<ll>(m));
  for (ll i = 0; i < n; ++i) for (ll j = 0; j < m; ++j) cin >> score[i][j];

  for (ll i = 0; i < m; ++i) for (ll j = i + 1; j < m; ++j) { // 2曲をiとjとする
    ll ten = 0;
    for (ll k = 0; k < n; ++k) {
      ten += max(score[k][i], score[k][j]);
    }
    ans = max(ans, ten);
  }

  cout << ans << '\n';
  return 0;
}