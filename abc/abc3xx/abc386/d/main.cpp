#include <bits/stdc++.h>
using namespace std;
namespace rng = std::ranges;
namespace vw  = std::views;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  ll n, m; cin >> n >> m;

  vector v(n, vector<ll>(n, -1));

  bool ok = true;
  while (m--) {
    ll x, y; char c; 
    cin >> x >> y >> c;
    x--; y--;

    if (ok == true) {
      if (c == 'B') {
        v[x][y] = 1;
        for (ll i = 0; i < y; ++i) {
          if (v[x][i] == -1 || v[x][i] == 1) {
            v[x][i] = 1;
          } else {
            cout << "No" << '\n';
            ok = false;
          }
        }
        if (ok == true) {
          for (ll i = 0; i < x; ++i) {
            if (v[i][y] == -1 || v[i][y] == 1) {
              v[i][y] = 1;
            } else {
              cout << "No" << '\n';
              ok = false;
            }
          }
        }
      } else { // white
        v[x][y] = 0;
        for (ll i = y + 1; i < n; ++i) {
          if (v[x][i] == -1 || v[x][i] == 0) {
            v[x][i] = 0;
          } else {
            cout << "No" << '\n';
            ok = false;
          }
        }
        if (ok == true) {
          for (ll i = x + 1; i < n; ++i) {
            if (v[i][y] == -1 || v[i][y] == 0) {
              v[i][y] = 0;
            } else {
              cout << "No" << '\n';
              ok = false;
            }
          }
        }
      }
    }
  }
  
  if (ok == true) {
      cout << "Yes" << '\n';
  }

  return 0;
}