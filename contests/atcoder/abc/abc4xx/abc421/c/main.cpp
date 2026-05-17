#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (n); ++i)
using namespace std;

int main()
{
    long long n;
    cin >> n;
    string s;
    cin >> s;
    vector<long long> la(0);
    vector<long long> lb(0);
    long long ans1 = 0, ans2 = 0;
    rep(i, 2 * n) if (s[i] == 'B') lb.push_back(i + 1);
    rep(i, n) ans1 += max(lb.at(i) - (2 * (i + 1)), 2 * (i + 1) - lb.at(i));
    rep(i, 2 * n) if (s[i] == 'A') la.push_back(i + 1);
    rep(i, n) ans2 += max(la.at(i) - (2 * (i + 1)), 2 * (i + 1) - la.at(i));
    cout << min(ans1, ans2) << endl;
}