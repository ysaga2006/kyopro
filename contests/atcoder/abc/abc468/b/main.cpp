#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = (1LL << 60);
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll m, d; cin >> m >> d;
  string s; cin >> s;

  vector<bool> ans(m);
  rep(i, m) {
    if (s[i] == 'G') {
      rep(j, d + 1) {
        if (i - j >= 0) ans[i - j] = true;
        if (i + j < m) ans[i + j] = true;
      }
    }
  }

  ll cnt = 0;
  rep(i, m) {
    if (ans[i] == false) cnt++;
  }

  cout << cnt << '\n';
  return 0;
}
