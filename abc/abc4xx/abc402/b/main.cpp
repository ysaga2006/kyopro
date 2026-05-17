#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    deque<int> dq;
    int q; cin >> q;
    while (q--) {
        int n; cin >> n;
        if (n == 1) {
            int x; cin >> x;
            dq.push_back(x);
        } else {
            cout << dq.front() << '\n';
            dq.pop_front();
        }
    }
    return 0;
}
