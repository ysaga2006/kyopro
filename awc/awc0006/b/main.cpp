#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, t; cin >> n >> k >> t;
    ll sum = 0;
    while (n--) {
        ll d, r; cin >> d >> r;
        if (r >= k * d) {
            sum += r;
        }
    }
    if (sum >= t) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}