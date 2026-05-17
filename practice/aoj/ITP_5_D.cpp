#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i < n + 1; i++)
    {
        if (i % 3 == 0)
        {
            cout << " " << i;
        }
        else if (i % 10 == 3)
        {
            cout << " " << i;
        }
        else if (((i - (i % 10)) / 10) % 10 == 3)
        {
            cout << " " << i;
        }
        else if (((i - (i % 100)) / 100) % 10 == 3)
        {
            cout << " " << i;
        }
        else if (((i - (i % 1000)) / 1000) % 10 == 3)
        {
            cout << " " << i;
        }
        else if (((i - (i % 10000)) / 10000) % 10 == 3)
        {
            cout << " " << i;
        }
    }
    cout << endl;
}