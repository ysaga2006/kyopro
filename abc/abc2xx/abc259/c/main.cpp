#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  string s, t; cin >> s >> t;

  auto rle = [&](string x) {
    vector<pair<char, ll>> res;
    res.push_back({'#', 0});

    for (ll i = 0; i < ll(x.size()); ++i) {
      if (x[i] != res.back().first) {
        res.push_back({x[i], 1});
      } else {
        res.back().second++;
      }
    }

    res.erase(res.begin());

    return res;
  };

  vector<pair<char, ll>> news = rle(s);
  vector<pair<char, ll>> newt = rle(t); 

  if (news.size() != newt.size()) {
    cout << "No" << '\n';
    return 0;
  } else {
    for (ll i = 0; i < ll(news.size()); ++i) {
      if (news[i].first != newt[i].first || news[i].second > newt[i].second || (news[i].first == newt[i].first && news[i].second < newt[i].second && news[i].second == 1)) {
        cout << "No" << '\n'; 
        return 0;
      } 
    }
  }

  cout << "Yes" << '\n';

  return 0;
}