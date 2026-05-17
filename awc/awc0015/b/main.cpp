#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k; cin >> n >> k;
    vector<ll> v(n);
    ll count = 0;
    for (int i = 0; i < n; i++) {
        cin >> v.at(i);
        if (v.at(i) >= k && count < 1) {
            cout << i + 1 << endl;
            count++;
        }
    }
    if (count == 0) {
        cout << -1 << endl;
    }
    return 0;
}