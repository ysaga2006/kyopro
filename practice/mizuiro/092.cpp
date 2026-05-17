#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while (true) {
    ll h;
    cin >> h;

    if (h == 0)
      return 0;

    ll ans = 0;

    vector v(h, vector<ll>(5));
    for (ll i = 0; i < h; ++i)
      for (ll j = 0; j < 5; ++j)
        cin >> v[i][j];

    auto keshi = [&]() -> ll {
      ll score = 0;
      for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < 1; ++j) {
          if (v[i][j] != -1 && v[i][j] == v[i][j + 1] && v[i][j + 1] == v[i][j + 2] && v[i][j + 2] == v[i][j + 3] && v[i][j + 3] == v[i][j + 4]) {
            score += v[i][j] * 5;
            v[i][j] = -1;
            v[i][j + 1] = -1;
            v[i][j + 2] = -1;
            v[i][j + 3] = -1;
            v[i][j + 4] = -1;
          }
        }

        for (ll j = 0; j < 2; ++j) {
          if (v[i][j] != -1 && v[i][j] == v[i][j + 1] && v[i][j + 1] == v[i][j + 2] && v[i][j + 2] == v[i][j + 3]) {
            score += v[i][j] * 4;
            v[i][j] = -1;
            v[i][j + 1] = -1;
            v[i][j + 2] = -1;
            v[i][j + 3] = -1;
          }
        }

        for (ll j = 0; j < 3; ++j) {
          if (v[i][j] != -1 && v[i][j] == v[i][j + 1] && v[i][j + 1] == v[i][j + 2]) {
            score += v[i][j] * 3;
            v[i][j] = -1;
            v[i][j + 1] = -1;
            v[i][j + 2] = -1;
          }
        }
      }

      ans += score;

      if (score == 0)
        return false;
      else
        return true;
    };

    auto ochi = [&]() -> bool {
      ll cnt = 0;
      for (ll i = h - 1; i >= 1; --i) {
        for (ll j = 0; j < 5; ++j) {
          if (v[i][j] == -1 && v[i - 1][j] != -1) {
            cnt++;
            v[i][j] = v[i - 1][j];
            v[i - 1][j] = -1;
          }
        }
      }
      if (cnt == 0)
        return false;
      else
        return true;
    };

    while (true) {
      if (keshi() == false) 
        break;
      while (ochi() == true) ochi();
    }

    cout << ans << '\n';
  }

  return 0;
}