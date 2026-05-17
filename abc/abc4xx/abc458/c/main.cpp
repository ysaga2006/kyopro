#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  ll n = s.size();
  ll ans = 0;
  for (ll i = 0; i < n; ++i) {
    if (s[i] == 'C')
      ans += 1 + min(i, n - i - 1);
  }
  cout << ans << '\n';

  return 0;
}
