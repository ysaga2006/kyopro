#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int num = i;
        int sum = 0;
        while (num < 10) {
            sum += num % 10;
            num /= 10;
        }
        if (sum == k) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}