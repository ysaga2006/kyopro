#pragma once

#include <bits/stdc++.h>
using namespace std;

template <class T>
struct Compress {
    vector<T> xs;

    Compress() = default;
    explicit Compress(const vector<T>& values) { add(values); build(); }

    void add(const T& x) { xs.push_back(x); }

    void add(const vector<T>& values) {
        xs.insert(xs.end(), values.begin(), values.end());
    }

    void build() {
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
    }

    int get(const T& x) const {
        return (int)(lower_bound(xs.begin(), xs.end(), x) - xs.begin());
    }

    const T& operator[](int i) const { return xs[i]; }
    int size() const { return (int)xs.size(); }
};

