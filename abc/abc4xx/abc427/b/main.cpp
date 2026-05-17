#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    int n, ans = 1;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        string num;
        num = to_string(ans);
        int l = num.size();
        for (int j = 0; j < l; j++) {
            ans += (num.at(j) - '0');
        }
    }
    cout << ans << endl;
    return 0;
}