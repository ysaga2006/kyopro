#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll ans = 0;

  ll r, c;
  cin >> r >> c;

  vector moti(r, vector<ll>(c));
  for (ll i = 0; i < r; ++i)
    for (ll j = 0; j < c; ++j)
      cin >> moti[i][j];

  for (ll bit = 0; bit < (1 << r); ++bit) {
    for (ll i = 0; i < r; ++i) {
      if (bit & (1 << i)) {
        for (ll j = 0; j < c; ++j) {
          moti[i][j] = 1 - moti[i][j];
        }
      }
    }

    for (ll i = 0; i < c; ++i) {
      ll cnt = 0;
      for (ll j = 0; j < r; ++j) {
        if (moti[j][i] == 0)
          cnt++;
      }
    }
  }

  cout << ans << '\n';
  return 0;
}