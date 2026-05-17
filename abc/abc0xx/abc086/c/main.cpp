#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    bool ok = true;
    int pre, now, past, nowt;
    pre = 0; past = 0;
    for (int i = 0; i < n; i++) {
        int t, x, y; cin >> t >> x >> y;
        nowt = t;
        now = x + y;
        int dis = abs(now - pre);
        int per = nowt - past;
        cout << dis << " " << per << '\n';
        if (!(dis <= per and per - dis + 2 % 2 == 0)) {
            ok = false;
            cout << ok << '\n';
            break;
        }
        pre = now;
        past = nowt;
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}
