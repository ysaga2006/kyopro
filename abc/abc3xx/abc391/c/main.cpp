#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    int res = 0;
    vector<vector<int>> v(n, vector<int>());
    // 巣iにいるのは鳩v.at(i)
    // 鳩iは巣w.at(i)にいる
    for (int i = 0; i < n; i++) {
        v.at(i).push_back(i);
    }
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        w.at(i) = i;
    }
    for (;q--;) {
        int num; cin >> num;
        if (num == 1) {
            int p, h; cin >> p >> h;
            p--; h--;
            remove(v.at(w.at(p)).begin(), v.at(w.at(p)).end(), p);
        } else {
        }
    }
    return 0;
}
