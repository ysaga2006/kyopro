#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        v.at(i) = make_pair(a, i + 1);
    }
    sort(v.begin(), v.end(), [](const auto &a, const auto &b) {
        if (a.first != b.first) {
            return a.first < b.first;
        } else {
            return a.second > b.second;
        }
    });
    cout << v.back().second << endl;
    return 0;
}