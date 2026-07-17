#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int upp = 0;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        v.at(i) = s;
        upp = max(int(s.size()), upp);
    }
    for (int i = 0; i < n; i++) {
        int num = (upp - v.at(i).size()) / 2;
        for (int i = 0; i < num; i++) {
            cout << ".";
        }
        cout << v.at(i);
        for (int i = 0; i < num; i++) {
            cout << ".";
        }
        cout << '\n';
    }
    return 0;
}