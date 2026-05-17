#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    ll upp = -100100100100;
    ll lop = 100100100100;
    ll upq = -100100100100;
    ll loq = 100100100100;
    for (ll i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;
        ll p = x + y;
        ll q = x - y;
        upp = max(upp, p);
        lop = min(lop, p);
        upq = max(upq, q);
        loq = min(loq, q);
    }
    cout << max(upp - lop, upq - loq) << endl;
    return 0;
}
