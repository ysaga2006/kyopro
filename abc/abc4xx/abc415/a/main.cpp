#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ll long long
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v(n); rep(i, n) cin >> v.at(i);
    int x; cin >> x;
    bool ok = false;
    rep(i, n) if(v.at(i) == x) ok = true;
    cout << (ok == true ? "Yes" : "No") << endl;
    return 0;
}