#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    vector<ll> v(n); // v.at(i)はv.at(i - 1)とv.at(i)が同じかを持つ。
    int pre = -1;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        // cout << c << " ";
        if (pre == c) {
            v.at(i)++;
        }
        pre = c;
    }
    // cout << endl;
    for (int i = 0; i < n - 1; i++) {
        v.at(i + 1) += v.at(i);
    } // v.at(i)はiまでに条件を満たす花壇が何個あるかをもつ

    for (int i = 0; i < n; i++) {
        cout << v.at(i) << " ";
    }
    cout << endl;

    while (q--) {
        int l, r; cin >> l >> r; --l; --r;
        if (l == 0) {
            cout << v.at(r) << '\n';
        } else if (r == n - 1) {
            int count = 0;
            ll val = v.at(n - 1) - v.at(l - 1);
            if (v.at(l) == v.at(l - 1)) {
                count++;
            }
            cout << val - count << endl;
        } else {
            int count = 0;
            ll val = v.at(r) - v.at(l - 1);
            if (v.at(l) == v.at(l - 1)) {
                count++;
            }
            cout << val - count << '\n';
        }
    }
    return 0;
}