#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<ll> a(7);
    for (int i = 0; i < 7; i++) {
        cin >> a.at(i);
    }
    vector<ll> b(7);
    for (int i = 0; i < 7; i++) {
        cin >> b.at(i);
    }
    ll sum = 0;
    for (int i = 0; i < 7; i++) {
        sum += a.at(i) * b.at(i);
    }
    cout << sum << endl;
    return 0;
}