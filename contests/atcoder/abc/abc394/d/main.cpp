#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    stack<char> st;
    for (char ele : s) {
        if ((!st.empty()) && ((st.top() == '(' && ele == ')') || (st.top() == '[' && ele == ']') || (st.top() == '<' && ele == '>'))) st.pop();
        else st.push(ele);
    }
    cout << (st.empty() ? "Yes" : "No") << '\n';
    return 0;
}
