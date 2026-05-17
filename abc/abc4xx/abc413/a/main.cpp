#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ll long long
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    int sum = 0;
    rep(i, n) {
        int a; cin >> a;
        sum += a;
    }
    cout << (sum <= m ? "Yes" : "No") << endl;
    return 0;
}