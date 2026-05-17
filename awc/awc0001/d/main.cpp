#include <iostream>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> p(m);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i) >> b.at(i);
    }
    return 0;
}