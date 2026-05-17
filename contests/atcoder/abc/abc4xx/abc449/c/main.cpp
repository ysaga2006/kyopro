#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, l, r; cin >> n >> l >> r;
    int count = 0;
    string s; cin >> s;
    vector<vector<int>> v(26, vector<int>());
    for (int i = 0; i < n; i++) {
        v.at(s[i] - 'a').emplace_back(i);
    }
    for (int i = 0; i < 26; i++) {
        int left = 0, right = 1; // rightが1にならないことも。
        while (right < int(v.at(i).size())) {
            cout << left << " " << right << '\n';
            int dis = v.at(i).at(right) - v.at(i).at(left);
            if (dis >= l && dis <= r) {
                count++; right++;
            } else if (dis < l) {
                right++;
            } else if (dis > r) {
                left++;
            }
            cout << count << '\n';
        }
    }
    cout << count << endl;
    return 0;
}
