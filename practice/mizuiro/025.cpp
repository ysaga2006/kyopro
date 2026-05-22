#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr std::array<int, 8> di = {-1, -1, -1, 0, 0, 1, 1, 1};
constexpr std::array<int, 8> dj = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while (true) {
    ll w, h;
    cin >> w >> h;
    if (w == 0 && h == 0) break;

    ll ans = 0;

    vector tizu(h, vector<bool>(w));
    for (ll i = 0; i < h; ++i)
      for (ll j = 0; j < w; ++j) {
        ll c;
        cin >> c;
        tizu[i][j] = c;
      }

    vector visited(h, vector<bool>(w, false));

    auto dfs = [&](auto dfs, ll i, ll j) -> bool {
      visited[i][j] = true;

      for (ll k = 0; k < 8; ++k) {
        ll ni = i + di[k], nj = j + dj[k];

        if (ni < 0 || nj < 0 || h <= ni || w <= nj) continue;
        if (visited[ni][nj] == true) continue;
        if (tizu[ni][nj] == false) continue;

        dfs(dfs, ni, nj);
      }

      return true;
    };

    for (ll i = 0; i < h; ++i)
      for (ll j = 0; j < w; ++j) {
        if (visited[i][j] == false && tizu[i][j] == 1) {
          ans++;
          dfs(dfs, i, j);
        }
      }

    cout << ans << '\n';
  }

  return 0;
}