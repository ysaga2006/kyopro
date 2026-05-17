#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
    int n;
    int ans = 0;
    cin >> n;
    vector<int> vec(n + 1);
    rep(i, n) cin >> vec.at(i + 1);
    for (int l = 1; l < n + 1; l++) {
        for (int r = l; r < n + 1; r++) {
            int sum = 0;
            int count = 0;
            for (int i = l; i < r + 1; i++) {
                sum += vec.at(i);
            }
            for (int i = l; i < r + 1; i++) {
                if (sum % vec.at(i) != 0) {
                    count ++;
                }
            }
            if (count == r - l + 1) {
                ans ++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}