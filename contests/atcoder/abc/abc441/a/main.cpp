#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int p, q, x, y; cin >> p >> q >> x >> y;
    if (q <= y && q + 99 >= y && p <= x && p + 99 >= x) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}