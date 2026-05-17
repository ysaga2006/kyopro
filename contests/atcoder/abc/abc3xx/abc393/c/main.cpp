#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    set<pair<int, int>> st;
    int ans = 0;
    while (m--) {
        int u, v; cin >> u >> v;
        if (st.contains({u, v}) || st.contains({v, u}) || u == v) {
            ans++;
        } else {
            st.insert({u, v});
        }
    }
    cout << ans << endl;
    return 0;
}
