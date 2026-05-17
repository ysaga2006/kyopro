#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m;
  cin >> n >> m;

  vector<string> s(n);
  for (ll i = 0; i < n; ++i) {
    cin >> s[i];
  }

  set<string> akan;

  for (ll i = 0; i < n; ++i) {
    string gomi = s[i];

    for (ll j = 0; j < m; ++j) {
      if (gomi[j] == '0') {
        gomi[j] = '1';
      } else {
        gomi[j] = '0';
      }
    }

    akan.insert(gomi);
  }

  string t(m, '0');

  while (akan.count(t)) {
    ll now = m - 1;

    while (now >= 0 && t[now] == '1') {
      t[now] = '0';
      now--;
    }

    if (now < 0) {
      cout << "No" << '\n';
      return 0;
    }

    t[now] = '1';
  }

  cout << "Yes" << '\n';
  cout << t << '\n';

  return 0;
}
