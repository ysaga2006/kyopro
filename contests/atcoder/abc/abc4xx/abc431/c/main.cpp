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
    int n, m, k;
    cin >> n >> m >> k;
    vector<long long> head(n);
    for (int i = 0; i < n; i++)
    {
        cin >> head.at(i);
    }
    vector<long long> body(m);
    for (int i = 0; i < m; i++)
    {
        cin >> body.at(i);
    }
    sort(head.begin(), head.end());
    reverse(head.begin(), head.end());
    sort(body.begin(), body.end());
    reverse(body.begin(), body.end());
    int count = 0;
    for (int i = 0; i < min(body.size(), head.size()); i++)
    {
        if (head.at(i) <= body.at(i))
        {
            count++;
        }
        else
        {
            head.erase(head.begin() + i);
            i--;
        }
    }
    if (count >= k)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}