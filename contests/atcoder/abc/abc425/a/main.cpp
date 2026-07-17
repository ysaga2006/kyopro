#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
    int n, t = 0;
    cin >> n;
    rep(i, n + 1) t += pow(i, 3) * pow(-1, i);
    cout << t << endl;
    return 0;
}