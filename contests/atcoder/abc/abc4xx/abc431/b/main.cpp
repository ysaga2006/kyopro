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

int main()
{
    int x, n, q;
    cin >> x >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v.at(i);
    }
    cin >> q;
    set<int> part;
    for (int i = 0; i < q; i++)
    {
        int p;
        cin >> p;
        p--;
        if (part.count(p) == 0)
        {
            part.insert(p);
            x += v.at(p);
        }
        else if (part.count(p) == 1)
        {
            part.erase(p);
            x -= v.at(p);
        }
        cout << x << endl;
    }
    return 0;
}