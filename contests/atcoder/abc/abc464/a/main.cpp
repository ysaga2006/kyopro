#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s; cin >> s;
  ll cnte = 0, cntw = 0;
  for (auto& c : s) {
    if (c == 'E') cnte++;
    else cntw++;
  }

  if (cnte < cntw) cout << "West" << '\n';
  else cout << "East" << '\n';
  return 0;

}
