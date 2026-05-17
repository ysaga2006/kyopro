#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> v(3);
    for (int i = 0; i < 3; i++) {
        int a; cin >> a;
        v.at(i) = a;
    }
    sort(v.begin(), v.end());
    if (v.at(0) * v.at(1) == v.at(2)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}