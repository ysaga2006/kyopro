#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n; string s;
  cin >> n >> s;

  deque<ll> dq;
  bool gyaku = false;

  rep(i, n) {
    if (gyaku == false) dq.push_back(i + 1);
    else dq.push_front(i + 1);

    if (s[i] == 'o') gyaku = 1 - gyaku;
  }

  if (gyaku == false) {
    rep(i, n) cout << dq[i] << " ";
  } else {
    rep(i, n) cout << dq[n - i - 1] << " ";
  }

  cout << '\n';
  
  return 0;
}
