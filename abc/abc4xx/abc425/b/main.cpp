#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ll long long
using namespace std;

int main()
{
    int n;
    cin >> n;
    // -1以外について、各数字が0個か1個であることがyesnoの判断条件
    // v.at(i)には数字iの個数を入れる。
    vector<int> v(n + 1);
    vector<int> x(n + 1);
    rep(i, n)
    {
        int a;
        cin >> a;
        x.at(i) = a;
        if (a != -1)
            v.at(a)++;
    }
    int count = 0;
    rep(i, n)
    {
        if (v.at(i + 1) == 0 || v.at(i + 1) == 1)
        {
            count++;
        }
    }
    if (count == n)
    {
        cout << "Yes" << endl;
        rep(i, n)
        {
            if (v.at(i + 1) == 0)
            {
                rep(j, n)
                {
                    if (x.at(j) == -1)
                    {
                        x.at(j) = i + 1;
                        break;
                    }
                }
            }
        }
        rep(i, n) { cout << x.at(i) << " "; }
        cout << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}