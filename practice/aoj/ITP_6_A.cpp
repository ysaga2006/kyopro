#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec.at(i);
    }
    for (int j = 0; j < n - 1; j++)
    {
        cout << vec.at(n - 1 - j) << " ";
    }
    cout << vec.at(0) << endl;
}
