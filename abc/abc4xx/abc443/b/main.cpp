#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k; cin >> n >> k;
    ll sum = 0;
    ll ans = 0;
    while (sum < k) {
        sum += n;
        n++;
        ans++;
    }
    cout << ans - 1 << endl;
    return 0;
}