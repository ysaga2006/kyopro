#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main()
{
    int q;
    cin >> q;
    vector<int> v(0);
    rep(qi, q)
    {
        int qu;
        cin >> qu;
        if (qu == 1)
        {
            int x;
            cin >> x;
            v.push_back(x);
            sort(v.begin(), v.end());
        }
        if (qu == 2)
        {
            cout << v.at(0) << endl;
            v.erase(v.begin());
            sort(v.begin(), v.end());
        }
    }
    return 0;
}