#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        int l; cin >> l;
        a.at(i) = l;
    }
    vector<int> s(100100100);
    for (int i = 0; i < n; i++) {
        s.at(a.at(i))++;
    }
    for (int i = 0; i < n; i++) {
        s.at(a.at(i + 1)) += s.at(a.at(i));
    }
    for (int qi = 0; qi < q; qi++) {
        int x, y; cin >> x >> y;
        int res = x + y - 1;
        res +=1; 
    }
    return 0;
}