#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

ll di[] = {1, -1, 0, 0};
ll dj[] = {0, 0, 1, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll h, w, d;
  cin >> h >> w >> d;

  vector dist(h, vector<ll>(w, -1));
  vector<string> g(h);
  queue<pair<ll, ll>> q;

  rep(i, h) {
    string x;
    cin >> x;
    rep(j, w) {
      if (g[i][j] == 'H') {
        q.push({i, j});
        dist[i][j] = 0;
      }
    }
  }

  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    if (dist[x][y] == d) continue;

    rep(i, 4) {
      ll nx = x + di[i];
      ll ny = y + dj[i];

      if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
      if (g[nx][ny] == '#') continue;
      if (dist[nx][ny] != -1) continue;

      dist[nx][ny] = dist[x][y] + 1;
    }

    ll ans = 0;
    rep(i, h) rep(j, w) {
      if (dist[i][j] != -1) {
        ans++;
      }
    }

    cout << ans << '\n';
  }
  return 0;
}
