#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long long a, b, c; cin >> a >> b >> c;

  if (a < pow(c, b)) cout << "Yes" << '\n';
  else cout << "No" << '\n';
  return 0;
}