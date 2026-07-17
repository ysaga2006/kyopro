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
    int n, k;
    string s;
    map<string, int> counts;
    cin >> n >> k >> s;
    for (int j = 0; j < n - k + 1; j++)
    {
        counts[s.substr(j, k)]++;
    }
    int max_fre = 0;
    for (auto const &[word, count] : counts)
    {
        if (count >= max_fre)
        {
            max_fre = count;
        }
    }
    set<string> ans;
    for (auto const &[word, count] : counts)
    {
        if (count == max_fre)
        {
            ans.insert(word);
        }
    }
    cout << max_fre << endl;
    for (string element : ans)
    {
        cout << element << " ";
    }
    cout << endl;
    return 0;
}