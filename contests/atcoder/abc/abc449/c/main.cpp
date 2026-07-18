#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = (1LL << 60);
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, l, r;
  string s;
  cin >> n >> l >> r >> s;

  vector cnt(26, vector<ll>{});
  rep(i, s.size()) cnt[s[i] - 'a'].push_back(i);

  rep(i, 26) sort(cnt.begin(), cnt.end());

  rep(i, 26) {
    for (auto x : cnt[i]) {
    }
  }
  return 0;
}

// iを固定すると、i+L <= j <= i+R