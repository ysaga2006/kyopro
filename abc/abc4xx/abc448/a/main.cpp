#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x; cin >> n >> x;
    while (n--) {
        int a; cin >> a;
        if (a < x) {
            x = a;
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}
