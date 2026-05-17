#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    ll sum = 0;
    ll pre = 100100100100;
    while (n--) {
        int d; cin >> d;
        if (pre < d) {
            sum += d / 2;
            pre = d;
        } else {
            sum += d;
            pre = d;
        }
    }
    cout << sum << endl;
    return 0;
}