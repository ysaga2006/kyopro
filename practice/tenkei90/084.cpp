#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = (1LL << 60);
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n; cin >> n;
  string s; cin >> s;

  ll ans = 0;
  for (ll l = 0; l < n; l++) {
    for (ll r = l; r < n; r++) {
      if (s[l] != s[r]) {
        ans += n - r;
        break;
      }
    }
  }

  cout << ans << '\n';
  return 0;
}