#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v.at(i);
    }
    for (;m--;) {
        int p, w; cin >> p >> w; p--;
        v.at(p) = w;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (v.at(i) < k) {
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}