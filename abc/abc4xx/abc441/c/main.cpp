#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, x; cin >> n >> k >> x;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++) {
        ll a; cin >> a;
        v.at(i) = a;
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    ll sum = 0;
    for (ll i = n - k; i < n; i++) {
        if (sum < x) {
            sum += v.at(i);
        }
        if (sum >= x) {
            if (i + 1 <= n) {
                cout << i + 1 << endl;
                break;
            } else {
                cout << "-1" << endl;
                break;
            }
        }
    }
    if (sum < x) {
            cout << -1 << endl;
        }
    return 0;
}