#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, y; cin >> x >> y;
    double cnt = 0;
    for (int i = 1; i < 7; i++) {
        for (int j = 1; j < 7; j++) {
            if (i + j >= x || max(i, j) - min(i, j) >= y) cnt++;
        }
    }
    cout << fixed << setprecision(10) << cnt / 36 << endl;
    return 0;
}