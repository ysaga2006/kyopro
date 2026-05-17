#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> v(n + 1);
  for (int i = 1; i < n + 1; i++) {
    int a;
    cin >> a;
    v.at(i) = a;
  }
  set<int> st;
  set<int> dup;
  for (int i = 1; i < n + 1; i++) {
    if (st.contains(v.at(i))) {
      st.insert(v.at(i));
      dup.insert(v.at(i));
    } else {
      st.insert(v.at(i));
    }
  }
  set<int> ans;
  for (auto ele : st) {
    if (!dup.contains(ele)) {
      ans.insert(ele);
    }
  }
  if (int(ans.size()) == 0) {
    cout << -1 << endl;
  } else {
    int big = *prev(ans.end());
    for (int i = 1; i < n + 1; i++) {
      if (v.at(i) == big) {
        cout << i << endl;
      }
    }
  }
  return 0;
}

/*
// Suggested Refactoring: Map Approach
// This efficiently groups indices by value using std::map.
// map automatically sorts keys, so traversing from the end checks largest
values first.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // Map: value -> list of indices (1-based)
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        mp[a].push_back(i);
    }

    // Iterate map in reverse order (largest value first)
    // map::rbegin() returns a reverse iterator to the last element
    for (auto it = mp.rbegin(); it != mp.rend(); ++it) {
        // it->first is the value (A_i)
        // it->second is the vector of indices
        if (it->second.size() == 1) {
            cout << it->second[0] << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}
*/