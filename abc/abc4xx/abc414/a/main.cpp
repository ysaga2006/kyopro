#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ll long long
using namespace std;

int main() {
    int n, l, r; cin >> n >> l >> r;
    int cnt = 0;
    rep(i, n) {
        int x, y; cin >> x >> y;
        if(x <= l && r <= y) cnt++;
    }
    cout << cnt << endl;
    return 0;
}