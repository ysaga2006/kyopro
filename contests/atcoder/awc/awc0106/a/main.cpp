#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, k;
  cin >> n >> k;
  ll cnt = 1, pre = -1;
  rep(i, n) {
    ll h; cin >> h;
    if (h == pre) cnt++;
    else cnt = 1, pre = h;

    if (cnt == k) {
      cout << "Yes" << '\n';
      return 0;
    }
  }
  cout << "No" << '\n';

  return 0;
}
