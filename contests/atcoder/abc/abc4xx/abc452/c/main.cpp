#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> b(n);
  for (int i = 0; i < n; ++i) {
    int A, B;
    cin >> A >> B;
    a[i] = A;
    b[i] = B;
    b[i]--;
  }

  ll m;
  cin >> m;
  vector<string> s(m);
  for (int i = 0; i < m; ++i) {
    cin >> s[i];
  }

  vector<vector<set<char>>> v(11, vector<set<char>>(11, set<char>{}));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < ll(s[i].size()); ++j) {
      v[s[i].size()][j].insert(s[i][j]);
    }
  }

  for (ll i = 0; i < m; ++i) {  // 脊髄
    ll cnt = 0;
    if (ll(s[i].size()) == n) {
      for (ll j = 0; j < n; ++j) {  // 肋、たて
        if (v[a[j]][b[j]].contains(s[i][j])) {
          cnt++;
        }
      }
      cout << (cnt == n ? "Yes" : "No") << '\n';
    } else {
      cout << "No" << '\n';
    }
  }
  return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     ll n; cin >> n;
//     vector<ll> a(n);
//     vector<ll> b(n);
//     for (int i = 0; i < n; ++i) {
//         int A, B; cin >> A >> B;
//         a[i] = A; b[i] = B;
//         b[i]--;
//     }

//     ll m; cin >> m;
//     vector<string> sekidui(m);
//     vector s(12, vector<string>{}); // 文字数ごとにもつ
//     for (int i = 0; i < m; ++i) {
//         string S; cin >> S;
//         sekidui[i] = S;
//         s[S.size()].push_back(S);
//     }

//     for (int i = 0; i < m; ++i) { // 脊髄
//         if (ll(sekidui[i].size()) == n) {
//             ll cnt = 0;
//             for (int j = 0; j < n; ++j) { // 肋骨、たて
//                 bool ok = false;
//                 for (auto ele : s[a[j]]) {
//                     if (ele[b[j]] == sekidui[i][j]) {
//                         ok = true;
//                         cnt++;
//                         break;
//                     }
//                 }
//                 if (ok == false) {
//                     cout << "No" << '\n';
//                     break;
//                 }
//             }
//             if (cnt == n) {
//                 cout << "Yes" << '\n';
//             }
//         } else {
//             cout << "No" << '\n';
//         }
//     }
//     return 0;
// }
