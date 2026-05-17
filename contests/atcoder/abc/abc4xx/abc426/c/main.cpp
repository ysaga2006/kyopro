#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    vector<int> v(n + 1); rep(i, n + 1) v.at(i) = i;
    rep(qi, q) {
        int x, y; cin >> x >> y;
        cout << v.at(x) << "\n";
        for (int i = x + 1; i < y; i++) {
            v.at(i) -= v.at(x);
        }
        rep(i, x) v.at(i) = 0;
    }
    return 0;
}