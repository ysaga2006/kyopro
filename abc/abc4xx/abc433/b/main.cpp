#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n + 1);
    for (int i = 1; i < n + 1; i++) cin >> vec.at(i); 

    cout << "-1" << endl;

    for (int i = 2; i < n + 1; i++) {
        int count = 0;
        for (int j = i - 1; j > 0; j--) {
            if (vec.at(j) <= vec.at(i)) count ++; 
            else if (vec.at(j) > vec.at(i)) {
                cout << j << endl;
                break;
            }
        }
        if (count == i - 1) {cout << "-1" << endl;}
    }
    return 0;
}