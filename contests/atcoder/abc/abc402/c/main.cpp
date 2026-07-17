#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(0));
    vector<int> cnt(0);
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int k; cin >> k;
        cnt.emplace_back(k);
        for (;k--;) {
            int a; cin >> a;
            a--;
            v.at(a).emplace_back(i);
        }
    }
    for (;n--;) {
        int b; cin >> b;
        b--;
        for (auto ele : v.at(b)) {
            cnt.at(ele)--;
            if (cnt.at(ele) == 0) {
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}