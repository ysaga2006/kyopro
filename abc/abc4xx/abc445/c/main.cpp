#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> cnt(n);
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v.at(i);
        v.at(i)--;
        if (v.at(i) == i) {
            cnt.at(i)++;
        }
    }
    for (int i = 0; i < n; i++) {
        // cout << "look" << i + 1 << endl;
        int val = i;
        while (1 - (cnt.at(v.at(val)) > 0)) {
            // cout << val + 1 << " " << v.at(val) + 1 << endl;
            val = v.at(val);
            v.at(val) = v.at(v.at(val));
        }
        v.at(i) = v.at(val);
        // for (auto ele : cnt) {
        //     cout << ele << " ";
        // }
        // cout << endl;
    }
    for (int i = 0; i < n; i++) {
        cout << v.at(i) + 1 << " ";
    }
    cout << '\n';
    return 0;
}