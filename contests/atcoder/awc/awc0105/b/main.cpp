#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, p; cin >> n >> p;
  vector<ll> s(n);
  rep(i, n) cin >> s[i];
  sort(s.begin(), s.end());
  ll ans = 0, sum = 0;
  rep(i, n) {
    if (sum + s[i] <= p) {
      sum += s[i];
      ans++;
    } else {
      break;
    }
  }

  cout << ans << '\n';
  return 0;
}
