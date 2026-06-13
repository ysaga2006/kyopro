#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll h, w, k; cin >> h >> w >> k;

  vector<string> s(h);
  rep(i, h) cin >> s[i];

  vector sum(h + 1, vector<ll>(w + 1));
  rep(i, h) rep(j, w) {
      sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + (s[i][j] - '0');
  }

  ll ans = 0;
  vector<ll> cnt(h * w + 1);

  for (ll top = 1; top <= h; ++top) {
    for (ll bot = top; bot <= h; ++bot) {
      vector<ll> history;

      cnt[0]++;
      history.push_back(0);

      for (ll c = 1; c <= w; ++c) {
        ll val = sum[bot][c] - sum[top - 1][c];

        if (val >= k) {
          ans += cnt[val - k];
        }

        cnt[val]++;
        history.push_back(val);
      }

      for (ll val : history) {
        cnt[val] = 0;
      }
    }
  }

  cout << ans << "\n";
  return 0;
}