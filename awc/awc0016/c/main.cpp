#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, l, r, t; cin >> n >> l >> r >> t;
    ll chp = 100100100100, yum = -1, idx = -1;
    for (int i = 1; i < n + 1; i++) {
        ll p, s; cin >> p >> s;
        if (l <= p && p <= r && s >= t) {
            if (chp > p) {
                chp = p; yum = s; idx = i;
            } else if (chp == p) {
                if (yum < s) {
                    yum = s; idx = i;
                } 
            }
        }
    }
    cout << idx << endl;
    return 0;
}