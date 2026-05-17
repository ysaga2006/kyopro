#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main()
{
    map<string, int> version = {
        {"Ocelot", 1},
        {"Serval", 2},
        {"Lynx", 3}};
    string x, y;
    cin >> x >> y;
    if (version[x] >= version[y])
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}