#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, L, k; cin >> n >> L >> k;
    vector<int> v(n + 1);
    int start = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        v.at(i) = a - start;
        start += v.at(i);
    }
    v.at(n) = L - start;

    // for (auto w : v) {
    //     cout << w << " ";
    // }
    // cout << endl;

    // 全ての部分の長さがx以上にできるかを判定する。
    auto ok = [&](int x) {
        int cnt = 0;
        int len = 0;
        for (auto ele : v) {
            len += ele;
            if (len >= x) {
                cnt++;
                len = 0;
            }
        }
        return cnt >= k + 1;
    };

    int l = -1, r = L + 1;
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        // cout << l << " " << m << " " << r << endl;
        if (ok(m)) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << l << endl;
    return 0;
}