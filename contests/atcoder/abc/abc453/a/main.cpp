#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n; 
  cin >> n;
  string s;
  cin >> s;
  ll now = 0;
  ll cnt = 0;
  while (s[now] == 'o') {
    cnt++;
    now++;
  }
  for (ll i = cnt; i < n; ++i) {
    cout << s[i];
  }
  cout << '\n';
  return 0;
}
