#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> v(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        sum += a;
        v.at(i) = a - b;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < k; i++) {
        sum -= v.at(n - 1 - i);
    }
    cout << sum << '\n';
    return 0;
}