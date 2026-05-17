#include <iostream>
#include <vector>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> v(n); 
    bool ok = false;
    for (int i = 0; i < n; i++) cin >> v.at(i);
    for (int i = 0; i < n; i++) {
        if (v.at(i) == k) {
            ok = true;
            cout << i + 1 << '\n';
            break;
        }
    }
    if (ok == false) {
        cout << -1 << '\n';
    }
    return 0;
}