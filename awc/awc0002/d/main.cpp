#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<int> c(n); for (int i = 0; i < n; i++) cin >> c.at(i); 
    vector<int> r(m); for (int i = 0; i < m; i++) cin >> r.at(i);
    int ans = 0;
    if (n < m) {
        for (int i = 0; i < n; i++) {
            if (c.at(i) <= r.at(m - n + i)) ans++;
        }
    } else {
        for (int i = 0; i < m; i++) {
            if (c.at(i) <= r.at(i)) ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}