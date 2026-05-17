#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  set<string> st;
  st.insert("()");
  set<string> ans;
  if (n == 2) {
    ans.insert("()");
  } else if (n % 2 != 0) {
    return 0;
  } else {
    int cnt = 0;
    while (cnt < (1 << (n - 3)) + 1) {
      for (auto ele : st) {
        string can1 = '(' + ele + ')';
        if (int(can1.size()) == n) {
          ans.insert(can1);
          cnt++;
        } else if (int(can1.size()) < n) {
          st.insert(can1);
          cnt++;
        }
        for (auto elee : st) {
          string can2 = ele + elee;
          if (int(can2.size()) == n) {
            ans.insert(can2);
            cnt++;
          } else if (int(can2.size()) < n) {
            st.insert(can2);
            cnt++;
          }
        }
      }
    }
  }
  for (auto s : ans) {
    cout << s << endl;
  }
  return 0;
}