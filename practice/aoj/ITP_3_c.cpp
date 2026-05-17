#include <iostream>
#include <string>
using namespace std;

int main()
{
    vector<vector<int>> data(3000, vector<int>(2));
    for (int i = 0; i < 3000; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> data.at(i).at(j);
        }
    }
    for (int k = 0; k < 3000; k++)
    {
        if (data.at(k).at(0) == 0 && data.at(k).at(1) == 0)
        {
            break;
        }
        if (data.at(k).at(1) - data.at(k).at(0) >= 0)
        {
            cout << data.at(k).at(0) << " " << data.at(k).at(1) << endl;
        }
        else
        {
            cout << data.at(k).at(1) << " " << data.at(k).at(0) << endl;
        }
    }
}