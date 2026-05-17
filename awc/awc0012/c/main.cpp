#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, m; cin >> n >> k >> m;
    vector<ll> nov;
    vector<ll> pro;
    while (n--) {
        ll h, p; cin >> h >> p;
        if (h == 0) {
            nov.emplace_back(p);
        }
        if (h == 1) {
            pro.emplace_back(p);
        }
    }
    sort(nov.begin(), nov.end());
    sort(pro.begin(), pro.end());
    reverse(nov.begin(), nov.end());
    reverse(pro.begin(), pro.end());
    if (ll(pro.size()) < m or ll(nov.size()) < (k - m)) {
        cout << -1 << endl;
    } else {
        ll sum = 0;
        for (int i = 0; i < m; i++) {
            sum += pro.at(i);
        }
        for (int i = 0; i < (k - m); i++) {
            sum += nov.at(i);
        }
        cout << sum << endl;
    }
    return 0;
}