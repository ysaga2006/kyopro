#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    ll sum = 0;
    int cnt = 0;
    while (n--) {
        int a, b; cin >> a >> b;
        if (a > b) {
            sum += a - b;
            cnt++;
        }
    }
    cout << cnt << " " << sum << endl;
    return 0;
}