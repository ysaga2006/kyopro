#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }
    // log_2(n) = at.(i)みたいなもの
    vector<int> lg(n + 1);
    lg.at(1) = 0;
    for (int i = 2; i <= n; i++) {
        lg.at(i) = lg.at(i / 2) + 1;
    }
    // 構築(O(N log N))
    int k = lg.at(n) + 1;
    vector<vector<int>> st(k, vector<int>(n));
    // 基底
    for (int i = 0; i < n; i++) {
        st.at(0).at(i) = a.at(i);
    }
    for (int i = 1; i < k; i++) {
        for (int j = 0; j + (1 << i) <= n; j++) {
            st.at(i).at(j) = max(st.at(i - 1).at(j), st.at(i - 1).at(j + (1 << (i - 1))));
        }
    }

    // クエリの処理
    while (q--) {
        int l, r; cin >> l >> r;
        l--; r--;
        int d = r - l + 1;
        int j = lg.at(d);
        cout << max(st.at(j).at(l), st.at(j).at(r - (1 << j) + 1)) << '\n';
    }
    return 0;
}