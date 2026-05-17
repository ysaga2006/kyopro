#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
    string s;
    cin >> s;
    int ans = 0;
    int l = s.size();
    for (int i = 1; i < ((l + 1) / 2); i++) {
        for (int j = 0; j < l - i + 1; j++) {
            int count = 0;
            for (int k = 0; k < i; k++) {
                if (s[j + k] == s[j + k + 1]) {
                    count ++;
                }
            }
            if (count == i) {
                int count2 = 0;
                for (int m = 0; m < i; m++) {
                    if (s[j + i + m] == s[j]) {
                        count2 ++;
                        if (count2 == i) {
                            ans ++;
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
}