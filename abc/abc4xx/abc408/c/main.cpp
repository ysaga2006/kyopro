#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<int> v(n + 2);
    for(;m--;) {
        int l, r; cin >> l >> r;
        v.at(l)++;
        v.at(r + 1)--;
    }
    vector<int> res(n + 1);
    int now = 0;
    for (int i = 0; i < n + 1; i++) {
        now += v.at(i);
        res.at(i) = now;
    }
    sort(res.begin(), res.end());
    cout << res.at(1) << endl;
    return 0;
}