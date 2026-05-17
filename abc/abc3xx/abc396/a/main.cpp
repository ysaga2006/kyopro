#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        v.at(i) = a;
    }
    int count = 0;
    for (int i = 0; i < n - 2; i++) {
        if (v.at(i) == v.at(i + 1) && v.at(i) == v.at(i + 2)) {
            count += 1;
        }
    }
    if (count > 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}