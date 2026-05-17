#include <bits/stdc++.h>
using namespace std;
namespace rng = std::ranges;
namespace vw = std::views;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  constexpr ll MAX = 100005;

  ll q;
  cin >> q;

  auto hantei = [&](ll x) {
    bool ok = true;
    for (ll i = 2; i * i <= x; ++i) {
      if (x % i == 0)
        ok = false;
    }

    ll y = (x + 1) / 2;
    for (ll i = 2; i * i <= y; ++i) {
      if (y % i == 0)
        ok = false;
    }

    if (ok == true)
      return 1;
    else
      return 0;
  };

  vector<ll> ans(MAX, 0);
  for (ll i = 0; i < MAX; ++i) {
    ans[i] = hantei(i);
  }
  ans[0] = 0;
  ans[1] = 0;
  ans[2] = 0;

  for (ll i = 0; i < MAX - 1; ++i) {
    ans[i + 1] += ans[i];
  }


  // for (ll i = 0; i < 54; ++i) {
  //   cout << "ans[" << i << "] is " << ans[i] << '\n';
  // }
  // cout << '\n';

  while (q--) {
    ll l, r;
    cin >> l >> r;
    if (l != 0) {
      cout << ans[r] - ans[l - 1] << '\n';
    } else {
      cout << ans[r] << '\n';
    }
  }
  return 0;
}