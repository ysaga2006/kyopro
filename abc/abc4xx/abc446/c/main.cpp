#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while (t--) {
        ll n, d; cin >> n >> d;
        ll old = 0;
        vector<ll> a(n);
        vector<ll> b(n);
        for (int i = 0; i < n; i++) {
            cin >> a.at(i);
        }
        for (int i = 0; i < n; i++) {
            cin >> b.at(i);
        }
        vector<ll> v(n + 1); // n日目に仕入れた卵の在庫
        // v.at(n) = 1001001000;
        for (int i = 0; i < n; i++) {
            v.at(i) += a.at(i);
            while (b.at(i) >= v.at(old) && old < i) {
                b.at(i) -= v.at(old);
                v.at(old) = 0;
                old++;
            }
            v.at(old) -= b.at(i);
            if (i >= d) {
                v.at(i - d) = 0;
            }   
        }
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            // cout << v.at(i) << '\n';
            sum += v.at(i);
        }
        cout << sum << '\n';
    }
    return 0;
}
