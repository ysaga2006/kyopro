#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    while (s.size() < n)
    {
        s.insert(0, "o");
    }
    cout << s << endl;
    return 0;
}