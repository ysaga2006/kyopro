#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  ll x; cin >> x;

  for (ll i = 1; i <= 10; ++i) {
    if (i == x) continue;
    cout << "HelloWorld"[i - 1];
  }

  cout << '\n';
  return 0;
}
