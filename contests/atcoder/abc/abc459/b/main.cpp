#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;
  const string x = "22233344455566677778889999";

  string ans = "";
  for (ll i = 0; i < n; ++i) {
    string s;
    cin >> s;
    ans += x[s[0] - 'a'];
  }

  cout << ans << "\n";

  return 0;
}