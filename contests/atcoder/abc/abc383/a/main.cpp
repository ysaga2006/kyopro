#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n; cin >> n;
  ll now = 0, pret = 0;
  rep(i, n) {
    ll t, v; cin >> t >> v;
    now = max(0ll, now - t);
    now += v;
  }
  cout << now << '\n';
  return 0;
}
