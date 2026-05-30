#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m; cin >> n >> m;
  ll cnt = 0;
  while (m != 0) {
    ll x = n % m;
    m = x;
    cnt++;
  }

  cout << cnt << '\n';
  return 0;
}
