#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w, q; cin >> h >> w >> q;
    while (q--) {
        int num; cin >> num;
        if (num == 1) {
            int r; cin >> r;
            h -= r;
            cout << r * w << '\n';
        } else {
            int c; cin >> c;
            w -= c;
            cout << c * h << '\n';
        }
    }
    return 0;
}
