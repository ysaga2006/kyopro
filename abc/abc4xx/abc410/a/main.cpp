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
    sort(v.begin(), v.end());
    int k; cin >> k;
    auto ans = lower_bound(v.begin(), v.end(), k);
    cout << n - (ans - v.begin()) << endl;
    return 0;
}