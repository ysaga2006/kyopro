#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    for (;t--;) {
        int n; cin >> n;
        int ans = 0;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            int r; cin >> r; r--;
            v.at(i) = n - r;
        }
        vector<int> sub(n - 1);
        for (int i = 0; i < n - 1; i++) {
            sub.at(i) = v.at(i + 1) - v.at(i);
        }
        auto start = max_element(v.begin(), v.end());
        for (auto i = start; i >= v.begin(); i--) {
            if (*(i - 1) - *i > 1) {
                ans += *(i - 1) - *i - 1;
                *i += *(i - 1) - *i - 1;
            } else if (*i - *(i - 1) > 1) {
                ans += *i - *(i - 1) - 1;
                *(i - 1) += *i - *(i - 1) - 1;
            }
        }
        for (auto i = start; i < v.end(); i++) {
            if (*i - *(i + 1) > 1) {
                ans += *i - *(i + 1) - 1;
                *(i + 1) += *i - *(i + 1) - 1;
            } else if (*(i + 1) - *i > 1) {
                ans += *(i + 1) - *i - 1;
                *i += *(i + 1) - *i - 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t; cin >> t;
//     for (;t--;) {
//         int n; cin >> n;
//         int ans = 0;
//         vector<int> v(n);
//         for (int i = 0; i < n; i++) {
//             int r; cin >> r; r--;
//             v.at(i) = r;
//         }
//         vector<int> sub(n - 1);
//         for (int i = 0; i < n - 1; i++) {
//             sub.at(i) = v.at(i + 1) - v.at(i);
//         }
//         ans += min(v.at(0), abs(sub.at(0)) - 1);
//         for (int i = 0; i < n - 2; i++) {
//             int val = min(v.at(i), abs(sub.at(i)) - 1);
//             ans += val;
//             sub.at(i + 1) += val;
//         }
//         ans += min(v.at(n - 1), abs(sub.at(n - 2)) - 1);
//         cout << ans << '\n';
//     }
//     return 0;
// }