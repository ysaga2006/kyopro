#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k; cin >> n >> k;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++) {
        cin >> v.at(i);
    }
    ll sum = 0;
    ll count = 0;
    for (ll i = 0; i < k; i++) {
        sum += v.at(i);
    }
    if (sum <= 0) {
        count++;
    }
    for (ll i = 1; i < n - k + 1; i++) {
        sum -= v.at(i - 1);
        sum += v.at(k - 1 + i);
        if (sum <= 0) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}