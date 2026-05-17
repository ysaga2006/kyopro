#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> v(201);
    for (int i = 1; i < n + 1; i++) {
        int t; cin >> t;
        v.at(t) = i;
    }
    int cnt = 0;
    for (int i = 0; i < 201; i++) {
        if (cnt == 3) {
            break;
        }
        if (v.at(i) > 0) {
            cout << v.at(i) << " ";
            cnt++;
        }
    }
    cout << endl;
    return 0;
}