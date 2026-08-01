#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = (1LL << 60);
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n; string s;
  cin >> n >> s;

  vector<ll> ng;
  rep(i, n) {
    if (s[i] == 'x') ng.push_back(i);
  }

  rep(k, n) {
    if (k >= ng.size()) {
      cout << n << '\n';
    } else {
      cout << ng[k] + 1 << '\n';
    }

  }
  return 0;
}
