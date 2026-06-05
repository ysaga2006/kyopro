#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll q; cin >> q;

  deque<ll> dq;

  while (q--) {
    ll t, x; cin >> t >> x;
    if (t == 1) {
      dq.push_front(x);
    } else if (t == 2) {
      dq.push_back(x);
    } else {
      cout << dq[x - 1] << '\n';
    }
  }
  return 0;
}