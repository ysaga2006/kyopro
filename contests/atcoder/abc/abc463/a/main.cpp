#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll x, y; cin >> x >> y;
  cout << (9 * x == 16 * y ? "Yes" : "No") << '\n'; 
  return 0;
}
