#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  const char A = 'A';
  const char AB = 'X';
  const char ABC = 'Y';

  ll t;
  cin >> t;
  rep(ti, t) {
    string s;
    cin >> s;
    stack<char> st;

    ll ans = 0;
    rep(i, s.size()) {
      if (s[i] == 'C') {
        while (!st.empty() && st.top() == A) {
          st.pop();
        }
        if (st.empty()) {
          ans++;
        } else {
          st.pop();
        }

      } else if (s[i] == 'B') {
        while (!st.empty() && st.top() == AB) {
          st.pop();
        }
        if (st.empty()) {
          ans++;
        } else {
          st.pop();
          st.push(AB);
        }
      } else {
        st.push(A);
      }
    }

    cout << ans << '\n';
  }
  return 0;
}
