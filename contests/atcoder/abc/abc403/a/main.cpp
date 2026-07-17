#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n; cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        v.at(i) = a;
    }


    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            sum += v.at(i);
        }
    }
    
    cout << sum << endl;
    return 0;
}