#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n; cin >> n;

  vector<ll> h(n);
  rep(i, n) cin >> h[i];

  ll ans = 1;
  rep(head, n) {
    for (ll dis = 1; dis < n - head; dis++) {
      ll cnt = 1;
      ll now = head + dis;
      while (now < n && h[now] == h[head]) {
        now += dis;
        cnt++;
      }
      ans = max(ans, cnt);
    }
  }

  cout << ans << '\n';
  return 0;
}
