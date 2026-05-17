#include <bits/stdc++.h>
using namespace std;
namespace rng = std::ranges;
namespace vw = std::views;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  const ll INF = 100100100100LL;
  
  ll a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  ll ans = INF;

  // ABの枚数で全探索する
  for (ll i = 0; i <= x * 2 || i <= y * 2; ++i) {
    ll val = 0;
    val += i * c;
    val += max(0LL, (x - (i / 2))) * a;
    val += max(0LL, (y - (i / 2))) * b;
    ans = min(ans, val);
  }

  cout << ans << '\n';

  return 0;
}