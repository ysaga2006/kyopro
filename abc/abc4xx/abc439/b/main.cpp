#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ll long long
using namespace std;

int main() {
    int n; cin >> n;
    set<int> st;
    while (n > 0 && st.count(n) == 0) {
        st.insert(n);
        int sum = 0;
        while (n >= 10) {
            int x = n % 10;
            n /= 10;
            sum += x * x;
        }
        sum += n * n;
        n = sum;
    }
    // for (auto num : st) {
    //     cout << num << endl;
    // }
    if (st.count(1) > 0) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}