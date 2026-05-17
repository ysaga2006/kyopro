#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    vector<int> v(n, 1);
    for (;q--;) {
        int t; cin >> t; t--;
        v.at(t) = 1 - v.at(t);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += v.at(i);
    }
    cout << ans << '\n';
    return 0;
}
