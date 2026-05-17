#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, l, r; cin >> n >> l >> r;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int p; cin >> p;
        if (l <= p && p <= r) {
            v.emplace_back(make_pair(p, i));
        }
    }
    sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
        if (a.first != b.first) {
            return a.first > b.first;
        }
        return a.second < b.second;
    });
    if (v.empty()) cout << -1 << '\n';
    else cout << v.front().second + 1 << '\n';
    return 0;
}