#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = (1LL << 60);
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;

  set<string> ans;

  auto good = [&](string x) -> bool {
    stack<char> st;
    for (char& c : x) {
      if (!st.empty()) {
        char tp = st.top();
        if (tp == '(' && c == ')') st.pop();
        else st.push(c);
      } else {
        st.push(c);
      }
    }

    if (st.empty()) return true;
    else return false;
  };

  for (ll bit = 0; bit < (1 << n); bit++) {
    string s = "";
    for (ll i = 0; i < n; i++) {
      if (bit & (1 << i)) {
        s.push_back('(');
      } else {
        s.push_back(')');
      }
    }

    if (good(s) == true) ans.insert(s);
  }

  for (string x : ans) {
    cout << x << '\n';
  }
  return 0;
}