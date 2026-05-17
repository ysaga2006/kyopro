#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ll long long
using namespace std;

int main() {
    int n; cin >> n;
    vector<string> s(n); rep(i, n) cin >> s.at(i);
    set<string> st;
    rep(i, n) rep(j, n) {
        if (i == j) continue;
        else {
            st.insert(s.at(i) + s.at(j));
        }
    }
    cout << st.size() << endl;
    return 0;
}