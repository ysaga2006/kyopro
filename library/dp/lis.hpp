#pragma once

#include <bits/stdc++.h>
using namespace std;

template <class T>
int lis_length(const vector<T>& a, bool strict = true) {
  vector<T> dp;
  for (const T& x : a) {
    auto it = strict ? lower_bound(dp.begin(), dp.end(), x)
             : upper_bound(dp.begin(), dp.end(), x);
    if (it == dp.end()) dp.push_back(x);
    else *it = x;
  }
  return (int)dp.size();
}

