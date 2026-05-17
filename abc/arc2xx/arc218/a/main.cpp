#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  ll n, m; cin >> n >> m;
  
  vector a(n, vector<ll>(m));
  for (ll i = 0; i < n; ++i) for (ll j = 0; j < m; ++j) {
    cin >> a[i][j];
  }

  return 0;
}
