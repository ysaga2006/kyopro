#include <iostream>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    ll sum = 0;
    while (n--) {
        int c, d; cin >> c >> d;
        if (c <= k) {
            sum += d;
        }
    }
    cout << sum << endl;
    return 0;
}