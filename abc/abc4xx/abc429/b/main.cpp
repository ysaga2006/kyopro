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
    int N, M, S = 0, C = 0;
    cin >> N >> M;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v.at(i);
        S += v.at(i);
    }
    for (int i = 0; i < N; i++)
    {
        if (S - v.at(i) == M)
        {
            C += 1;
        }
    }
    if (C > 0)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}