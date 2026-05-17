#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
    int w, b;
    cin >> w >> b;
    int n = 0;
    while (w * 1000 >= n * b) {
        n++;
    }
    cout << n << endl;
    return 0;
}