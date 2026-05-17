#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ll long long
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    rep(i, n)
    {
        int a;
        cin >> a;
        v.push_back(a);
        if (v.size() >= 4)
        {
            bool ok = true;
            rep(j, 3)
            {
                if (v.at(v.size() - 2 - j) != a)
                {
                    ok = false;
                }
            }
            if (ok == true)
            {
                rep(k, 4)
                {
                    v.pop_back();
                }
            }
        }
    }
    cout << v.size() << endl;
    return 0;
}