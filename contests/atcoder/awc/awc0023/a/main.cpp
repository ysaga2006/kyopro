#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, r; cin >> n >> m >> r;
    ll sum = 0;
    while (n--) {
        ll t; cin >> t;
        sum += t;
    }
    cout << sum + ll(m * r) << endl;
    return 0;
}