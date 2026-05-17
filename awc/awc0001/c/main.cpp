#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v.at(i);
    }
    sort(v.begin(), v.end());
    ll sum = 0;
    for (int i = 0; i < n - k; i++) {
        sum += v.at(i);
    }
    cout << sum << '\n';
    return 0;
}