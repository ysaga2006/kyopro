#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  

  ll n; cin >> n;
  string s; cin >> s;

  vector<ll> ans;
  ans.push_back(s[0]);

  for (ll i = 1; i < n; ++i) {
    if (s[i] != ans.back()) {
      ans.push_back(s[i]);
    }
  }

  cout << ans.size() << '\n';

  return 0;
}
