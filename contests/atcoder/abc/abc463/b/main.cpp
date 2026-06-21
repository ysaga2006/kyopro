#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n; char x;
  cin >> n >> x;

  ll m;
  if (x == 'A') m = 0;
  if (x == 'B') m = 1;
  if (x == 'C') m = 2;
  if (x == 'D') m = 3; 
  if (x == 'E') m = 4;

  vector<string> s(n);
  rep(i, n) cin >> s[i];
  
  bool ok = false;
  rep(i, n) {
    if (s[i][m] == 'o') ok = true;
  }

  cout << (ok == true ? "Yes" : "No") << '\n';
  return 0;
}
