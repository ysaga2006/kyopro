#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  ll t; cin >> t;
  while (t--) {
    string a, b; cin >> a >> b;
    string st;
    for (auto mozi : a) {
      st.push_back(mozi);

      while (ll(st.size() >= 4)) {
        if (st.substr(ll(st.size()) - 4) == "(xx)") {
          for (ll i = 0; i < 4; ++i) st.pop_back();
          for (ll i = 0; i < 2; ++i) st.push_back('x');
        } else {
          break;
        }
      }
    }

    string st2;
    for (auto mozi : b) {
      st2.push_back(mozi);

      while (ll(st2.size() >= 4)) {
        if (st2.substr(ll(st2.size()) - 4) == "(xx)") {
          for (ll i = 0; i < 4; ++i) st2.pop_back();
          for (ll i = 0; i < 2; ++i) st2.push_back('x');
        } else {
          break;
        }
      }
    }

    if (st == st2) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }

  }
  return 0;
}
