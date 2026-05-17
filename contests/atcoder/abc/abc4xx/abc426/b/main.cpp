#include <bits/stdc++.h>
#define rep(i, n) for (int i = 2; i < (n); ++i)
using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<char> w(s.begin(), s.end());
    map<char, int> mp;
    mp[w.at(0)]++;
    if (mp[w.at(1)] == 0)
    {
        mp[w.at(1)]++;
        if (w.at(2) == w.at(0))
        {
            cout << w.at(1) << endl;
        }
        else if (w.at(2) == w.at(1))
        {
            cout << w.at(0) << endl;
        }
    }
    else if (mp[w.at(1)] == 1)
    {
        rep(i, w.size()) if (w.at(i) != w.at(0))
        {
            cout << w.at(i) << endl;
        }
    }
    return 0;
}