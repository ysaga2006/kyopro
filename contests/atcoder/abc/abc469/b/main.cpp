#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = (1LL << 60);
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;
  string s;
  cin >> s;

  ll ans = 0;

  if (n == 1) {
    if (s[0] == 'x') ans = 1;
    else ans = 0;
  } else {
    rep(i, n) {
      if (i == 0) {
        if (s[1] == 'x' && s[0] == 'x') ans++;
      } else if (i == n - 1) {
        if (s[n - 2] == 'x' && s[n - 1] == 'x') ans++;
      } else {
        if (s[i] == 'x' && s[i + 1] == 'x' && s[i - 1] == 'x') ans++;
      }
    }
  }

  cout << ans << '\n';
  return 0;
}
