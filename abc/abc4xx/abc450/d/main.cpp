#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> v(n);
    int upp = -1;
    for (int i = 0; i < n; i++) {
        cin >> v.at(i);
        upp = max(upp, v.at(i));
    }
    for (int i = 0; i < n; i++) {
        v.at(i) += k * ((upp - v.at(i)) / k);
    }
    sort(v.begin(), v.end());
    int sub = v.back() - v.front();
    int top = 0;
    for (int i = 0; i < n - 1; i++) {
        v.at(i) += k;
        top = max(top, v.at(i));
        sub = min(sub, top - v.at(i + 1));
    }
    cout << sub << endl;
    return 0;
}
