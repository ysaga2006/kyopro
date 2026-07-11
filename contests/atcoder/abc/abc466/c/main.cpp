#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll ans = 0, l = 1;
  ll n; cin >> n;

  for (ll r = 2; r < n; r++) {
    while (l < r) {
      cout << "?" << " " << l << " " << r << endl;

      string res; cin >> res;
      if (res == "Yes") {
        break;
      } else {
        l++;
      }
    }
    ans += r - l;
  }

  cout << "!" << " " << ans << '\n';
  return 0;
}
