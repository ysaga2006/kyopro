#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    deque<int> dq(n);
    for (int i = 0; i < n; i++) {
        dq.at(i) = i + 1;
    }
    for (;q--;) {
        int m; cin >> m;
        if (m == 1) {
            int p, x; cin >> p >> x;
            dq.at(p - 1) = x;
        }
        else if (m == 2) {
            int p; cin >> p;
            cout << dq.at(p - 1) << endl;
        }
        else if (m == 3) {
            int k; cin >> k;
            for (int i = 0; i < k % n; i++) {
                dq.push_back(dq.at(0));
                dq.pop_front();
            }
        }
    }
    return 0;
}