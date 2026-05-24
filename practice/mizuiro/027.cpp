#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

constexpr std::array<int, 4> di4 = {-1, 0, 1, 0};
constexpr std::array<int, 4> dj4 = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll m, n;
  cin >> m >> n;

  vector mp(n, vector<ll>(m));
  rep(i, n) rep(j, m) cin >> mp[i][j];

  auto dfs = [&](auto dfs, ll i, ll j) -> void {
    rep(k, 4) {
      ll ni = i + di4[k], nj = j + dj4[k];

      if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
      
    }
  };
  return 0;
}