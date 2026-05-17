#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    int min = 100;
    vector<int> v(n + 1);
    for (int qi = 0; qi < q; qi++) {
        int x; cin >> x;
        if (x > 0) {
            v.at(x)++;
            cout << x << " ";
        } else {
            for (int j = 0; j < n; j++) {
                if (v.at(j) <= min) {
                    min = v.at(j);
                }
            }
            for (int k = 0; k < n; k++) {
                if (v.at(k) == min) {
                    v.at(k)++;
                    cout << k + 1 << " ";
                    break;
                }
            }
        }
    }
    cout << endl;
    return 0;
}