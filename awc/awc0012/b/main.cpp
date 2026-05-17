#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, t, c, d; cin >> n >> t >> c >> d;
    ll count = 0;
    while (n--) {
        ll w; cin >> w;
        if (w >= t) {
            count++;
        }
    }
    cout << min(c, d) * count << endl;
    return 0;
}