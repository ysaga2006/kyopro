#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = (1LL << 60);
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll h, w; cin >> h >> w;
  if (w >= 25 * h * h) cout << "Yes" << '\n';
  else cout << "No" << '\n';
  return 0;
}
