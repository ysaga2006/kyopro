#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, d; cin >> n >> m >> d;
    ll count = 0;
    while (n--) {
        ll t; cin >> t;
        count += max((t - m + d - 1) / d, ll(0));
    }
    cout << count << endl;
    return 0;
}