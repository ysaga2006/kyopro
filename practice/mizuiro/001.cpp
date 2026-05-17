// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_B

#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int solve() {
  ll n, x; cin >> n >> x;
  if (n == 0 && x == 0) return -1;

  ll cnt = 0;

  for (ll i = 1; i <= n; ++i) {
    for (ll j = i + 1; j <= n; ++j) {
      for (ll k = j + 1; k <= n; ++k) {
        if (i + j + k == x) cnt++;
      }
    }
  }

  cout << cnt << '\n';
  
  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while (solve() == 0);
  
  return 0;
}