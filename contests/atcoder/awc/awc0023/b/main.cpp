#include <iostream>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n; n--;
    ll num = 0;
    while (n--) {
        ll a, b; cin >> a >> b;
        num += a;
        num -= min(num, b);
    }
    ll a; cin >> a;
    num += a;
    cout << num << endl;
    return 0;
}