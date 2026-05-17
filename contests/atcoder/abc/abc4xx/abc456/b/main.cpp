#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  vector saiko(3, vector<ll>(6));
  for (ll i = 0; i < 3; ++i) {
    for (ll j = 0; j < 6; ++j) {
      cin >> saiko[i][j];
    }
  }

  double cnt = 0;
  for (ll i = 0; i < 6; ++i) for (ll j = 0; j < 6; ++j) for (ll k = 0; k < 6; ++k) {
    vector<bool> ok(3, false);
    if (saiko[0][i] == 4 || saiko[1][j] == 4 || saiko[2][k] == 4) ok[0] = true;
    if (saiko[0][i] == 5 || saiko[1][j] == 5 || saiko[2][k] == 5) ok[1] = true;
    if (saiko[0][i] == 6 || saiko[1][j] == 6 || saiko[2][k] == 6) ok[2] = true;

    if (ok[0] == true && ok[1] == true && ok[2] == true) cnt++;
  }

  cout << fixed << setprecision(10) << cnt / 216 << '\n';

  return 0;
}
