#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ll long long
using namespace std;

int main() {
    int n, s; cin >> n >> s;
    vector<int> v(n + 1); rep(i, n) cin >> v.at(i + 1);
    v.at(0) = 0;
    bool ok = true;
    rep(i, n) {
        if(v.at(i + 1) - v.at(i) >= s + 0.5) {
            ok = false;
        }
    }
    cout << (ok == true ? "Yes" : "No") << endl;
    return 0;
}