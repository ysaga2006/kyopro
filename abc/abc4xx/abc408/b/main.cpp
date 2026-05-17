#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    set<int> st;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        st.insert(a);
    }
    cout << st.size() << endl;
    for (auto ele : st) {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}