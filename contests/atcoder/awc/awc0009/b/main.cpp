#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, s, c; cin >> n >> s >> c;
    ll k = 0;
    ll hp = s;
    while (n--) {
        int h, p; cin >> h >> p;
        if (hp >= h) {
            hp -= h;
            hp += p;
        } else {
            k++;
        }
    }
    cout << k * c << endl;
    return 0;
}