#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector v(1001000, vector<int>(2));
    for (int i = 0; i < 1001000; i++) {
        v[i][0] = -1001000;
    }
    int ans = 1001000;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        v[a][1] = i;
        ans = min(ans, v[a][1] - v[a][0] + 1);
        v[a][0] = v[a][1];
    }
    if (ans == 1001000) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}
