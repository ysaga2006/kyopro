#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    ll upp = 0;
    int count = 0;
    while (n--) {
        int h; cin >> h;
        if (h > upp) {
            count++;
            upp = h;
        }
    }
    cout << count << endl;
    return 0;
}