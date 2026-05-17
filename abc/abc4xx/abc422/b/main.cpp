#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
    int h , w;
    int black = 0, check = 0;
    cin >> h >> w;
    vector<vector<char>> vec(h, vector<char>(w));
    rep(i, h) rep(j, w) {
        cin >> vec.at(i).at(j);
        if (vec.at(i).at(j) == '#') {
            black ++;
        }
    }
    rep(i, h) rep(j, w) {
        int count = 0;
        rep(k, h) rep(l, w) {
            if (vec.at(i).at(j) == '#') {
                if (abs(i - k) + abs(j - l) == 1) {
                    if (vec.at(k).at(l) == '#') {
                        count ++;
                    }
                }
            }   
        }
        if (count == 2 || count == 4) {
            check ++;
        }   
    }
    if (check == black) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}