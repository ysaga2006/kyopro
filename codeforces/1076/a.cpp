#include <iostream>
#include <string>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    for (;t--;) {
        int n, s, x; cin >> n >> s >> x;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            sum += a;
        }
        while (sum < s) {
            sum += x;
        }
        if (sum == s) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
}