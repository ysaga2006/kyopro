#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string num = "1234567890";

  string s; cin >> s;
  ll n = s.size();

  rep(i, n) if (num.contains(s[i])) cout << s[i];
  cout << '\n';
  return 0;
}
