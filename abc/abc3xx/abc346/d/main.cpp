#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    string s; cin >> s;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    vector<ll> l0(n + 1), l1(n + 1), r0(n + 1), r1(n + 1); // 左or右から見ていって同じ数字が来たらcを足す。これをiまでやった時のsum
    for (int i = 0; i < n; i++) {
        l0[i + 1] = l0[i];
        l1[i + 1] = l1[i];
        if (i % 2 == 0) {
            if (s[i] == '0') {
                l1[i + 1] += c[i];
            } else {
                l0[i + 1] += c[i];
            }
        } else {
            if (s[i] == '1') {
                l1[i + 1] += c[i];
            } else {
                l0[i + 1] += c[i];
            }
        }
    }
    for (int i = n - 1; i > -1; i--) {
        r0[i] = r0[i + 1];
        r1[i] = r1[i + 1];
        if (i % 2 == 0) {
            if (s[i] == '1') {
                r1[i + 1] += c[i];
            } else {
                r0[i + 1] += c[i];
            }
        } else {
            if (s[i] == '0') {
                r1[i + 1] += c[i];
            } else {
                r0[i + 1] += c[i];
            }
        }
    }
    ll ans = 1e18;
    for (int i = 1; i < n; i++) {
        ans = min(ans, l0[i] + r1[i]);
    }
    for (int i = 1; i < n; i++) {
        ans = min(ans, l1[i] + r0[i]);
    }
    cout << ans << '\n';
    return 0;
}
