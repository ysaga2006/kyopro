#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> vec(n);
    rep(i, n) cin >> vec.at(i);
    int left = x * *max_element(vec.begin(), vec.end());
    int right = y * *min_element(vec.begin(), vec.end());
    int ma = 0;
    for (int i = min(left, right); i <= max(left, right); i++)
    {
        if (*min_element(vec.begin(), vec.end()) <= i / y && *max_element(vec.begin(), vec.end()) <= i / x && i > ma)
            ma = i;
    }
    int total = 0;
    rep(i, n) total += vec.at(i);
    rep(i, total) if ((ma * n - y * i) / x == total - i && (ma * n - y * i) % x == 0) cout << i << endl;
    return 0;
}