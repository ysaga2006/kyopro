#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    ll wa = 0;
    vector<ll> v(n);
    set<ll> ans;
    for (ll i = 0; i < n; i++) {
        ll a; cin >> a;
        v.at(i) = a;
        wa += a;
    }
    sort(v.begin(), v.end());
    ll cnt = 0;
    if (n % 2 == 0) {
        ll sum = v.at(0) + v.at(n - 1);
        for (ll i = 1; i < n / 2; i++) {
            if (v.at(i) + v.at(n - 1 - i) == sum) {
                cnt++;
            }
        }
        if (cnt == n / 2 - 1) {
            ans.insert(wa / (n / 2));
        }
    }
    cnt = 0;
    ll upp = v.at(n - 1);
    ll max = 0;
    for (ll i = 0; i < n; i++) {
        if (v.at(i) == upp) {
            max++;
        }
    }
    // cout << max << endl;
    if ((n - max) % 2 == 0) {
        for (ll i = 0; i < (n - max) / 2; i++) {
            if (v.at(i) + v.at(n - max - 1 - i) == upp) {
                cnt++;
            } else {
                break;
            }
        }
        if (cnt == (n - max) / 2) {
            ans.insert(wa / (max + cnt));
        }
    }
    for (auto ele : ans) {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}