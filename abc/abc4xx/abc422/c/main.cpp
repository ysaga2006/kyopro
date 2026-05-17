#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
    int t;
    cin >> t;
    rep(i, t) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a > c) {
            cout << min(b + (a - c), c) << endl;
        }
        else {
            cout << min(b + (c - a), a) << endl;
        }
    }
    return 0;
}