#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ll long long
using namespace std;

int main() {
    string s, t; cin >> s >> t;
    set<char> st;
    rep(i, int(s.size() - 1)) {
        if (isupper(s[i + 1])) {
            st.insert(s[i]);
        }
    }
    bool ok = true;
    for (auto ele : st) {
        bool okk = false;
        rep(i ,int(t.size())) {
            if (t[i] == ele) {
                okk = true;
            }
        }
        if (okk == false) {
            ok = false;
        }
    }
    cout << (ok == true ? "Yes" : "No") << endl;
    return 0;
}