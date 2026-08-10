#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = (1LL << 60);
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll h, w;
  cin >> h >> w;

  if (h == 1 || w == 1) cout << h * w << '\n';
  else {
    if (h % 2 == 1) h++;
    if (w % 2 == 1) w++;

    cout << h * w / 4 << '\n';
  }
  return 0;
}