// https://judge.u-aizu.ac.jp/onlinejudge/submission.jsp#submit/ALDS1_4_B

#include <bits/stdc++.h>
using namespace std;
namespace rng = std::ranges;
namespace vw = std::views;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll ans = 0;

  ll n; cin >> n;

  vector<ll> s(n);
  for (ll i = 0; i < n; ++i) cin >> s[i];

  ll q; cin >> q;

  for (ll i = 0; i < q; ++i) {
    ll t; cin >> t;
    if (rng::binary_search(s, t) == true) ans++;
  }

  cout << ans << '\n';
  
  return 0;
}