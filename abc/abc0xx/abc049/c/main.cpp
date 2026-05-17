#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    const string a = "dream";
    const string b = "dreamer";
    const string c = "erase";
    const string d = "eraser";

    while (true) {
        int l = s.size();
        bool matched = false;

        if (l >= 7 && s.substr(l - 7) == b) {
            s.erase(l - 7);
            matched = true;
        } else if (l >= 6 && s.substr(l - 6) == d) {
            s.erase(l - 6);
            matched = true;
        } else if (l >= 5 && s.substr(l - 5) == a) {
            s.erase(l - 5);
            matched = true;
        } else if (l >= 5 && s.substr(l - 5) == c) {
            s.erase(l - 5);
            matched = true;
        }


        if (!matched || s.empty()) break;
    }

    if (s.empty()) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}