#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w; cin >> h >> w;
    int up = h + 1, down = -1, left = w + 1, right = -1;

    vector<string> v(h); 

    for (int i = 0; i < h; i++) {
        cin >> v[i];
        for (int j = 0; j < w; j++) {
            if (v[i][j] == '#') {
                up = min(up, i);
                down = max(down, i);
                left = min(left, j);
                right = max(right, j);
            }
        }
    }

    for (int i = up; i <= down; i++) {
        for (int j = left; j <= right; j++) {
            if (v[i][j] == '.') {
                cout << "No\n";
                return 0;
            }
        }
    }

    cout << "Yes\n";
    return 0;
}
