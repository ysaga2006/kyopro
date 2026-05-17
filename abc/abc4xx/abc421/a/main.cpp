#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
    int n, x;
    string y;
    cin >> n;
    vector<string> vec(n);
    rep(i, n) cin >> vec.at(i);
    cin >> x >> y;
    if (vec.at(x - 1) == y) {
        cout << "Yes" << endl;
    } 
    else {
        cout << "No" << endl;
    }
    return 0;
}