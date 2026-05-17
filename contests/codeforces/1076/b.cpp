#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    for (;t--;) {
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            int p; cin >> p;
            v.at(i) = p;
        }
        int l = 0;
        int r = 0;
        while (l < n && v.at(l) == n - l) l++;
        for (int i = 0; i < n; i++) {
            if (v.at(i) == n - l) {
                r = i;
                break;
            }
        }
        reverse(v.begin() + l, v.begin() + r + 1);
        for (int i = 0; i < n; i++) {
            cout << v.at(i) << " ";
        }
        cout << '\n';
    }
    return 0;
}