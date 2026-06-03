#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n; cin >> n;

  vector a(n, vector<ll>(n, 0));

  for (ll i = 0; i < n; ++i) {
    for (ll j = 0; j <= i; ++j) {
      if (j == 0 || j == i) a[i][j] = 1;
      else a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
    }

    rep(k, i + 1) cout << a[i][k] << " ";
    cout << '\n'; 
  }
  return 0;
}