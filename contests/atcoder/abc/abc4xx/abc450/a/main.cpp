#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        if (i != n - 1) {
            cout << n - i << ",";
        } else {
            cout << n - i;
        }
    }
    return 0;
}
