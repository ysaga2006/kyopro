#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, t; cin >> n >> t;
    ll sum = 0;
    for (;n--;) {
        ll a, b; cin >> a >> b;
        sum += max(a - b * t, ll(0));
    }
    cout << sum << '\n';
    return 0;
}