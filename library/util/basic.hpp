#pragma once

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

constexpr int INF_INT = 1'000'000'000;
constexpr ll INF = 4'000'000'000'000'000'000LL;
constexpr ld EPS = 1e-12L;
constexpr ll MOD = 998244353LL;
constexpr ll MOD1 = 1'000'000'007LL;
constexpr ll MOD9 = 998244353LL;

template <class T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template <class T>
bool chmin(T& a, const T& b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}

template <class T>
T floor_div(T a, T b) {
  assert(b != 0);
  if (b < 0) a = -a, b = -b;
  if (a >= 0) return a / b;
  return -((-a + b - 1) / b);
}

template <class T>
T ceil_div(T a, T b) {
  assert(b != 0);
  if (b < 0) a = -a, b = -b;
  if (a >= 0) return (a + b - 1) / b;
  return -((-a) / b);
}

template <class T>
vector<int> argsort(const vector<T>& a) {
  vector<int> p((int)a.size());
  iota(p.begin(), p.end(), 0);
  stable_sort(p.begin(), p.end(), [&](int i, int j) { return a[i] < a[j]; });
  return p;
}
