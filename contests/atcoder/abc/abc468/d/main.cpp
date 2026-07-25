#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = (1LL << 60);
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s; cin >> s;
  ll n = s.size();

  ll ans = 0;

  rep(i, n) {
    ll cnt = 0;
    rep(j, n) {
      if (i - j < 0 || i + j >= n) break;
      if (s[i + j] != s[i - j]) cnt++;
      if (cnt >= 2) break;
      ans++;
    }
  }

  rep(i, n) {
    ll cnt = 0;
    rep(j, n) {
      if (i - j < 0 || i + j + 1 >= n) break;
      if (s[i - j] != s[i + j + 1]) cnt++;
      if (cnt >= 2) break;
      ans++;
    }
  }

  cout << ans << '\n';
  return 0;
}
