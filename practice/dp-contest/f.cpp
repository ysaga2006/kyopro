#include <bits/stdc++.h>
using ll = long long;
using namespace std;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true; }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true; }
    return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s, t; cin >> s >> t;
  
  vector dp(ll(s.size()) + 1, vector<ll>(ll(t.size()) + 1, 0));

  for (ll i = 0; i < ll(s.size()); ++i) {
    for (ll j = 0; j < ll(t.size()); ++j) {
      if (s[i] == t[j]) chmax(dp[i + 1][j + 1], dp[i][j] + 1);
      chmax(dp[i + 1][j + 1] ,dp[i + 1][j]);
      chmax(dp[i + 1][j + 1], dp[i][j + 1]);
    }
  }

  string res = "";
  ll i = s.size(), j = t.size();
  while (i > 0 && j > 0) {
    if (dp[i][j] == dp[i - 1][j]) {
      i--;
    } else if (dp[i][j] == dp[i][j - 1]) {
      j--;
    } else {
      res = s[i - 1] + res;
      i--; j--;
    }
  }

  cout << res << '\n';

  return 0;
}