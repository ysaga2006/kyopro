#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, c, d; cin >> a >> b >> c >> d;
    cout <<  ((c * 60 + d < a * 60 + b) ? "Yes" : "No" ) << endl;
    return 0;
}