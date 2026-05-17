#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
    int H, W;
    while (true)
    {
        cin >> H >> W;
        if (H == 0 && W == 0)
        {
            break;
        }
        for (int j = 0; j < W; j++)
        {
            cout << "#";
        }
        cout << endl;
        for (int i = 0; i < H - 2; i++)
        {
            cout << "#";
            for (int k = 0; k < W - 2; k++)
            {
                cout << ".";
            }
            cout << "#" << endl;
        }
        for (int j = 0; j < W; j++)
        {
            cout << "#";
        }
        cout << endl;
        cout << " " << endl;
    }
}