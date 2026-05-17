#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    int count = 0;
    vector<vector<string>> v(n, vector<string>());
    for (int i = 0; i < n; i++) {
        int m; cin >> m;
        for (int j = 0; j < m; j++) {
            string w; cin >> w;
            v.at(i).emplace_back(w);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            set<string> st;
            for (auto work : v.at(i)) {
                st.insert(work);
            }
            for (auto work2 : v.at(j)) {
                st.insert(work2);
            }

            // for (auto ele : st) {
            //     cout << ele << " ";
            // }
            // cout << endl;

            if (int(v.at(i).size() + v.at(j).size() - st.size()) >= k) {
                count++;
                // cout << count << endl;
            }
        }
    }
    cout << count << endl;
    return 0;
}