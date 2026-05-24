#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t; cin >> t;
  while (t--) {
    string ans;

    string s; cin >> s;
    ll n = s.size();

    vector<ll> cnt(26, 0);
    for (char c : s) cnt[c - 'a']++;

    if (*max_element(cnt.begin(), cnt.end()) > (n + 1) / 2) {
      cout << "No" << '\n';
      continue;
    }

    priority_queue<pair<ll, char>> pq;
    for (ll i = 0; i < 26; ++i) {
      if (cnt[i] > 0) pq.push({cnt[i], char('a' + i)});
    }

    while (!pq.empty()) {
      auto [kosu, moji] = pq.top();
      pq.pop();

      if (!ans.empty() && ans.back() == moji) {
        auto [kosu2, moji2] = pq.top();
        pq.pop();

        ans.push_back(moji2);
        kosu2--;

        if (kosu2 > 0) pq.push({kosu2, moji2});
        if (kosu > 0) pq.push({kosu, moji});
      } else {
        ans.push_back(moji);
        kosu--;

        if (kosu > 0) pq.push({kosu, moji});
      }
    }

    cout << "Yes" << '\n';
    cout << ans << '\n';
  }

  return 0;
}
