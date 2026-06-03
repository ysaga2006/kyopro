#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

constexpr std::array<int, 4> di = {-1, 0, 1, 0};
constexpr std::array<int, 4> dj = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll h, w; cin >> h >> w;
  ll rs, cs, rt, ct; cin >> rs >> cs >> rt >> ct;
  rs--; cs--; rt--; ct--;

  vector<string> v(h);
  rep(i, h) cin >> v[i];

  vector visited(h, vector<bool>(w, false));

  queue<pair<ll, ll>> q;
  q.push({rs, cs});

  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();
    
    visited[i][j] = true;

    rep(k, 4) {
      ll ni = i + di[k], nj = j + dj[k];
      if (visited[ni][nj] == true) continue;
      if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
    }
  }
  
  return 0;
}