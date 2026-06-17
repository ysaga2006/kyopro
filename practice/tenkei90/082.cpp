#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

const ll MOD = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll l, r; cin >> l >> r;
  
  ll ans = 0;

  for (int i = l; i <= r; i++) {
    string s = to_string(i);
    ll n = s.size();
    ans += n * i;
    ans %= MOD;
  }

  cout << ans << '\n';
  return 0;
}