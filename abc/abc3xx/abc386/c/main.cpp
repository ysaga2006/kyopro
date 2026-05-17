#include <bits/stdc++.h>
using namespace std;
namespace rng = std::ranges;
namespace vw  = std::views;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  ll k; cin >> k;

  string s, t;
  cin >> s >> t;

  if (abs(ll(s.size()) - ll(t.size())) >= 2) cout << "No" << '\n'; 

  else if (ll(s.size()) + 1 == ll(t.size())) {
    ll cnt = 0;
    for (ll i = 0; i < ll(s.size()); ++i) {
      if (s[i] != t[i]) {
        if (s.substr(i, ll(s.size()) - i) == t.substr(i + 1, ll(s.size()) - i)) {
          cout << "Yes" << endl;
          break;
        } else {
          cout << "No" << endl;
          break;
        }
      } else {
        cnt++;
      }
    }
    if (cnt == s.size()) cout << "Yes" << endl;
  }

  else if (ll(t.size()) + 1 == ll(s.size())) {
    ll cnt = 0;
    for (ll i = 0; i < ll(t.size()); ++i) {
      if (s[i] != t[i]) {
        if (s.substr(i + 1, ll(t.size()) - i) == t.substr(i, ll(t.size()) - i)) {
          cout << "Yes" << endl;
          break;
        } else {
          cout << "No" << endl;
          break;
        }
      } else {
        cnt++;
      }
    }
    if (cnt == t.size()) cout << "Yes" << endl;
  }

  else if (ll(t.size()) == ll(s.size())) {
    ll cnt = 0;
    for (ll i = 0; i < ll(s.size()); ++i) {
      if (s[i] != t[i]) cnt++;
      if (cnt > 1) {
        cout << "No" << endl;
        return 0;
      }
    }
    if (cnt <= 1) {
      cout << "Yes" << endl;
    }
  }
  return 0;
}