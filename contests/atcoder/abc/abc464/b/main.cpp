#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll h, w;
  cin >> h >> w;

  ll up = 0, down = h - 1, right = w - 1, left = 0;

  vector<string> s(h);
  rep(i, h) cin >> s[i];

  rep(i, h) {
    bool ok = true;
    rep(j, w) {
      if (s[i][j] == '#') ok = false;
    }
    if (ok == true) up++;
    else break;
  }

  rep(i, h) {
    bool ok = true;
    rep(j, w) {
      if (s[h - 1 - i][j] == '#') ok = false;
    }
    if (ok == true) down--;
    else break;
  }

  rep(i, w) {
    bool ok = true;
    rep(j, h) {
      if (s[j][i] == '#') ok = false;
    }
    if (ok == true) left++;
    else break;
  }

  rep(i, w) {
    bool ok = true;
    rep(j, h) {
      if (s[j][w - 1 - i] == '#') ok = false;
    }
    if (ok == true) right--;
    else break;
  }

  for (ll i = up; i <= down; i++) {
    for (ll j = left; j <= right; j++) {
      cout << s[i][j]; 
    }
    cout << '\n';
  }

  return 0;
}
