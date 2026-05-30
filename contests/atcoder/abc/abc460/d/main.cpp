#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

const ll di[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const ll dj[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll h, w;
  cin >> h >> w;

  vector ans(h, vector<char>(w, '.'));

  vector<string> v(h);
  rep(i, h) cin >> v[i];

  vector dist(h, vector<ll>(w, -1));
  queue<pair<ll, ll>> q;

  rep(i, h) rep(j, w) {
    if (v[i][j] == '.') {
      bool ok = false;
      rep(k, 8) {
        ll ni = i + di[k], nj = j + dj[k];
        if (0 <= ni && ni < h && 0 <= nj && nj < w) {
          if (v[ni][nj] == '#') {
            ok = true;
            break;
          }
        }
      }
      if (ok == true) {
        dist[i][j] = 0;
        q.push({i, j});
      }
    }
  }

  if (q.empty()) {
    rep(i, h) {
      rep(j, w) cout << '.';
      cout << '\n';
    }
    return 0;
  }

  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();
    rep(k, 8) {
      ll ni = i + di[k], nj = j + dj[k];
      if (ni < 0 || h <= ni || nj < 0 || w <= nj) continue;
      if (dist[ni][nj] != -1) continue;

      dist[ni][nj] = dist[i][j] + 1;
      q.push({ni, nj});
    }
  }

  rep(i, h) rep(j, w) {
    if (dist[i][j] != -1 && dist[i][j] % 2 == 1) ans[i][j] = '#';
  }

  rep(i, h) {
    rep(j, w) cout << ans[i][j];
    cout << '\n';
  }
  return 0;
}