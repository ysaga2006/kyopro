// clang-format off
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b){if(a<b){a=b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b){if(a>b){a=b; return true;} return false;}

// clang-format on
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll ans = 0;

  ll h, w, n;
  cin >> h >> w >> n;

  map<ll, vector<ll>> mp;
  for (ll i = 0; i < n; ++i) {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    mp[a].push_back(b);
  }

  for (auto& [r, v] : mp) {
    sort(v.begin(), v.end());
    ll aida = -1;
    
    for (ll i = 0; i < ll(v.size()) - 1; ++i) {
      chmax(aida, v[i + 1] - v[i]);
    }

    ans += 2 * (w - 1 - aida);

  }

  return 0;
}
