#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ll long long
using namespace std;

int main() {
    int n; cin >> n;
    int cnt = 0;
    rep(i, n) {
        int a, b; cin >> a >> b;
        if (a < b) cnt++;
    }
    cout << cnt << endl;
    return 0;
}