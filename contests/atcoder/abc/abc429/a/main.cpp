#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>
#include <cctype>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        if (i < M)
        {
            cout << "OK" << endl;
        }
        if (i >= M)
        {
            cout << "Too Many Requests" << endl;
        }
    }
    return 0;
}