#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll dx[] = {-1, 0, 1, 0};
  ll dy[] = {0, 1, 0, -1};
  char dr[] = {'U', 'R', 'D', 'L'};
  
  ll t; cin >> t;
  while (t--) {
    ll n, a, b; cin >> n >> a >> b;
    a--; b--;

    vector visited(n, vector<bool>(n, false));
    visited[0][0] = true;

    bool found = false;
    string path = "";
    
    auto dfs = [&](auto dfs, ll x, ll y, ll count) -> void {
      if (found == true) return;

      if (x == n - 1 && y == n - 1 && count == n * n - 1) {
        found = true;
        return;
      }

      for (ll i = 0; i < 4; ++i) {
        ll nx = x + dx[i];
        ll ny = y + dy[i];

        if (0 <= nx && nx < n && 0 <= ny && ny < n) {
          if (visited[nx][ny] == false && !(nx == a && ny == b)) {
            visited[nx][ny] = true;
            path.push_back(dr[i]);

            dfs(dfs, nx, ny, count + 1);

            if (found == true) return;

            path.pop_back();
            visited[nx][ny] = false;
            
          }
        } 
      }
    };

    dfs(dfs, 0, 0, 1);

    if (found == true) {
      cout << "Yes" << endl;
      cout << path << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
