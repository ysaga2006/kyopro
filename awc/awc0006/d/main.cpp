#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m; cin >> n >> m;
    vector<pair<ll, ll>> v(m);
    for (ll i = 0; i < m; i++) {
        cin >> v.at(i).first >> v.at(i).second;
    }
    sort(v.begin(), v.end());
    ll count = 0; // 警備員の数
    ll end = 0; // 警備が行き届いている最終地点
    ll idx = 0;

    // lがend未満の警備員のうち、一番rが大きいものを探して、endをそのrにする。
    while (end < n) {
        ll reach = -1;
        while (idx < m && v.at(idx).first <= end + 1) {
            reach = max(reach, v.at(idx).second);
            idx++;
        }
        if (reach <= end) {
            cout << -1 << endl;
            return 0;
        }
        end = reach;
        count++;
    }
    cout << count << endl;
    return 0;
}

