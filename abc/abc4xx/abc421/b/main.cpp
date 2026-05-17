#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (n); ++i)
using namespace std;

int main() {
    string x, y;
    vector<string> vec(10);
    cin >> x >> y;
    vec.at(0) = x;
    vec.at(1) = y;
    rep(i, 8) {
        long long a = stoll(vec.at(i)), b = stoll(vec.at(i + 1));
        vec.at(i + 2) = to_string(a + b);
        string z = vec.at(i + 2);
        reverse(z.begin(), z.end());
        vec.at(i + 2) = z;
    }
    cout << stoll(vec.at(9)) << endl;
    return 0;
}