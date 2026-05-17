#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, w, k; cin >> n >> w >> k;
    if (w >= (n - 1) * k) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}