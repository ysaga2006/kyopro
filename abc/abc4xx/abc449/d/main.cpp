#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int count(int a, int b) {
    int x = max(a, -a), y = max(b, -b);
    int cnt = 0;
    int lower = min(x, y);
    int upper = max(x, y);
    for (int i = 0; i <= lower; i++) {
        if (i % 2 == 0) {
            cnt += i * 2 + 1;
        }
    }
    for (int i = lower + 1; i <= upper; i++) {
        if (i % 2 == 0) {
            cnt += lower + 1;
        }
    }
    cnt -= ((x / 2) + (y / 2) + 1);
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int l, r, d, u; cin >> l >> r >> d >> u;
    if (l < 0 && 0 < r) {
        if (d < 0 && 0 < u) {
            cout << count(r, u) + count(l, u) + count(r, d) + count(l, d) + (u / 2) + (-d / 2) + (-l / 2) + (r / 2) + 1 << endl; 
        } else {
            cout << count(r, u) + count(l, u) + (u / 2) << endl;
        }
    } else {
        if (d < 0 && 0 < u) {
            cout << count(d, r) + count(u, r) + (r / 2) << endl;
        } else {
            cout << count(r, u) - count(l, d) - ((d / 2) * (r - l) / 2) - ((l / 2) * (u - d) / 2) << endl;
        }
    }
    return 0;
}
