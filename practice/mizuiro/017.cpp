#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll k; cin >> k;
  ll cnt = 0;

  vector masu(8, vector<ll>(8, 1));
  
  auto fill = [&](ll r, ll c) {
    masu[r][c] = 9;
    cnt++;

    for (ll i = 0; i < r; ++i) {
      masu[i][c] = 0;
    }

    for (ll i = 0; i < c; ++i) {
      masu[r][i] = 0;
    }
    
    for (ll i = -7; i < 7; ++i) {
      if (0 <= r + i && r + i < 8 && 0 <= c + i && c + i < 8) masu[r + i][c + i] = 0;
    }

    for (ll i = -7; i < 7; ++i) {
      if (0 <= r - i && r - i < 8 && 0 <= c + i && c + i < 8) masu[r - i][c + i] = 0;
    }
    
  };

  for (ll i = 0; i < k; ++i) {
    ll r, c; cin >> r >> c;
    fill(r, c);
  }

  for (ll i = 0; i < 8; ++i) for (ll j = 0; j < 8; ++j) {
    if (masu[i][j] == true) fill(i, j);
    if (cnt == 8) break; 
  }

  for (ll i = 0; i < 8; ++i) {
    for (ll j = 0; j < 8; ++j) {
      if (masu[i][j] == 9) cout << "Q";
      else cout << ".";
    }
    cout << '\n';
  }

  return 0;
}