#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, l, w; cin >> n >> l >> w;
    int count = 0;
    while (n--) {
        int d; cin >> d;
        if (l - w <= d and d <= l + w) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}