#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s; ll n; cin >> s >> n;

  cout << s.substr(n, ll (s.size()) - 2 * n) << '\n';
  return 0;
}
