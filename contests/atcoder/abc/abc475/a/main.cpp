#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = (1LL << 60);
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s; cin >> s;
  ll n = s.size();

  rep(i, n - 1) {
    cout << s[i] << 'o';
  }

  cout << s[n - 1] << '\n';
  return 0;
}
