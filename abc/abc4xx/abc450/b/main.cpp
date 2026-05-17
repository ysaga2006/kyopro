#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            cin >> v.at(i).at(j);
        }
    }
    bool ok = false;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            for (int k = j; k < n; k++) {
                // cout << v.at(i).at(k) << " " << v.at(i).at(j) + v.at(j).at(k) << endl;
                if (v.at(i).at(k) > v.at(i).at(j) + v.at(j).at(k)) ok = true;
            }
        }
    }
    cout << (ok == true ? "Yes" : "No") << endl;
    return 0;
}
