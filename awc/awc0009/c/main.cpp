#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, t, k; cin >> n >> t >> k;
    ll count = 0;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v.at(i);
    }
    sort(v.begin(), v.end());
    ll d = v.front();
    for (int i = 0; i < n; i++) {
        v.at(i) -= d - 1;
        // cout << v.at(i) << endl;
        if (v.at(i) <= t + k) {
            count++;
            // cout << count << endl;
        } else {
            break;
        }
    }
    cout << count << endl;
    return 0;
}