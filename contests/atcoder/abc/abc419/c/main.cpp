#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<int, int>> cr;
    vector<pair<int, int>> st;
    rep(i, n) {
        int c, r; cin >> r >> c;
        cr.emplace_back(r, c);
    }
    rep(i, n) {
        st.emplace_back(cr[i].first, cr[i].second);
        st.emplace_back(cr[i].first, cr[i].second + 1);
        st.emplace_back(cr[i].first, cr[i].second - 1);
        st.emplace_back(cr[i].first + 1, cr[i].second);
        st.emplace_back(cr[i].first + 1, cr[i].second + 1);
        st.emplace_back(cr[i].first + 1, cr[i].second - 1);
        st.emplace_back(cr[i].first - 1, cr[i].second - 1);
        st.emplace_back(cr[i].first - 1, cr[i].second);
        st.emplace_back(cr[i].first - 1, cr[i].second + 1);
    }
    return 0;
}