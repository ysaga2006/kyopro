#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> inp(5);
    vector<int> v(5);
    vector<int> ans = {1, 2, 3, 4, 5};
    bool ok = false;
    for (int i = 0; i < 5; i++) {
        int a; cin >> a;
        inp.at(i) = a;
    }
    for (int i = 0; i < 4; i++) {
        v = inp;
        swap(v.at(i), v.at(i + 1));
        if (v == ans) {
            ok = true;
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}
