#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> w(2 * 100000 + 1);
    int max = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        w.at(i) = a;
        if (max < a) max = a;
    }
    vector<int> v(max + 5);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        v.at(0) += 1;
        v.at(w.at(i)) -= 1; 
    }
    for (int i = 1; i < max + 2; i++) {
        v.at(i) += v.at(i - 1);
    }
    for (int i = 0; i < max + 2; i++) {
        if(v.at(i) >= 10) {
            v.at(i + 1) += v.at(i) / 10;
            v.at(i) = v.at(i) % 10;
        }
    }
    while (v.at(ll(v.size()) - 2) == 0) {
        v.pop_back();
    }
    reverse(v.begin(), v.end());
    for (int i = 1; i < ll(v.size()); i++) {
        cout << v.at(i);
    }
    cout << endl;
    return 0;
}
