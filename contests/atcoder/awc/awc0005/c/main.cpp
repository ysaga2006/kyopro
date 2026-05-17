#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll ans = 0;
    ll n, k; cin >> n >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v.at(i);
    }
    for (int i = 1; i < n; i++) {
        ans += max(v.at(i), v.at(i - 1) - k) - v.at(i);
        v.at(i) = max(v.at(i), v.at(i - 1) - k);
    }
    for (int i = n - 2; i >= 0; i--) {
        ans += max(v.at(i + 1) - k, v.at(i)) - v.at(i);
        v.at(i) = max(v.at(i + 1) - k, v.at(i));
    }
    cout << ans << '\n';
    return 0;
}