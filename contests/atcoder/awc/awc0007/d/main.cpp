#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b;
    int count = 0;
    cin >> n >> a >> b;
    vector<vector<int>> aa(n, vector<int>(n));
    vector<vector<int>> bb(n, vector<int>(n));
    for (int i = 0; i < a; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--; c1--; r2--; c2--;
        for (int r = r1; r <= r2; r++) {
            for (int c = c1; c <= c2; c++) {
                aa.at(r).at(c)++;
            }
        }
    }
    for (int i = 0; i < b; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--; c1--; r2--; c2--;
        for (int r = r1; r <= r2; r++) {
            for (int c = c1; c <= c2; c++) {
                bb.at(r).at(c)++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (aa.at(i).at(j) > 0 && bb.at(i).at(j) > 0) {
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}