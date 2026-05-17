#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll sum = 0;
    ll n, m, s, t; cin >> n >> m >> s >> t;
    while (m--) {
        ll p, v; cin >> p >> v;
        if (min(s, t) <= p && p <= max(s, t)) {
            sum += v;
            // cout << sum << endl;
        }
    }
    cout << sum << endl;
    return 0;
}