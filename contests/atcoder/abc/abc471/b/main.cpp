#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = (1LL << 60);
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n; cin >> n;
  map<string, ll> s;
  rep(i, n) {
    string x; cin >> x;

    for (char& c : x) {
      char d = tolower(c);
      c = d;
    }
    
    s[x]++;
  }

  ll ans = 0;
  for (auto [ele, num] : s) {
    ans = max(ans, num);
  }

  cout << ans << '\n';

  return 0;
}
