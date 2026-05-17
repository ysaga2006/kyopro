#include <bits/stdc++.h>
using namespace std;
using ll = long long;

# include <iostream>
# include <vector>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    priority_queue<ll, vector<ll>, greater<ll>> que;
    ll q; cin >> q;
    while (q--) {
        ll num; cin >> num;
        if (num == 1) {
            ll h; cin >> h;
            que.push(h);
        } else {
            ll h; cin >> h;
            while ((1 - que.empty()) && que.top() <= h) {
                que.pop();
            }
        }
        cout << que.size() << '\n';
    }
    return 0;
}
