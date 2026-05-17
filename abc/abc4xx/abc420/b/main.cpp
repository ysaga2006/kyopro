#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> vec(n);
    vector<int> num(m);
    vector<int> sco(n);
    rep(i, n) cin >> vec.at(i);
    rep(i, n) rep(j, m)
    {
        if (vec.at(i)[j] == '1')
        {
            num.at(j)++;
        }
    }
    rep(i, m)
    {
        if (num.at(i) == n || num.at(i) == 0)
        {
            rep(j, n)
            {
                sco.at(j)++;
            }
        }
        else if (num.at(i) > (n / 2))
        {
            rep(j, n)
            {
                if (vec.at(j)[i] == '0')
                {
                    sco.at(j)++;
                }
            }
        }
        else
        {
            rep(j, n)
            {
                if (vec.at(j)[i] == '1')
                {
                    sco.at(j)++;
                }
            }
        }
    }
    int max = *max_element(sco.begin(), sco.end());
    rep(i, n)
    {
        if (sco.at(i) == max)
        {
            cout << i + 1 << " ";
        }
    }
    cout << endl;
    return 0;
}