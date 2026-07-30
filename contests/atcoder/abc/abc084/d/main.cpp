#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = (1LL << 60);
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  set<ll> st;
  rep(i, 1005) {
    bool ok = true;
    ll r = sqrt(i) + 1;
    for (ll j = 2; j <= r; j++) {
      if (i % j == 0) ok = false;
    }
    
    if (ok == true) st.insert(i);
  }

  for (auto& x : st) {
    cout << x << " ";
  }
  cout << '\n';
  return 0;
}
