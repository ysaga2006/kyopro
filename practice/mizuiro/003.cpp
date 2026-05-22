#include <bits/stdc++.h>
using namespace std;
namespace rng = std::ranges;
namespace vw  = std::views;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  string s; cin >> s;
  ll n = s.size();

  auto f = [&](string x) {
    bool ok;
    ll cnt = 0;
    for (char moji : x) {
      if (string("ATGC").contains(moji)) cnt++;
    }
    
    if (cnt == ll(x.size())) ok = true;
    else ok = false;

    return ok;
  };

  for (ll len = n; len >= 0; --len) {
    for (ll i = 0; i < n - len + 1; ++i) {
      if (f(s.substr(i, len)) == true) {
        cout << len << '\n';
        return 0;
      }
    }
  }

  return 0;
}
