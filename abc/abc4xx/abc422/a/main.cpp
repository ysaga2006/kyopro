#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
    char f, s, t;
    cin >> f >> s >> t;
    if (t == '8') {
        cout << f - '0' + 1 << "-" << "1" << endl;
    }
    else {
        cout << f - '0' << "-" << t - '0' + 1 << endl;
    }
}