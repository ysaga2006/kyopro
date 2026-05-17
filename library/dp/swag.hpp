#pragma once

#include <bits/stdc++.h>
using namespace std;

template <class T, T (*op)(T, T)>
struct Swag {
    vector<pair<T, T>> front_stack;
    vector<pair<T, T>> back_stack;

    bool empty() const { return front_stack.empty() && back_stack.empty(); }
    int size() const { return (int)front_stack.size() + (int)back_stack.size(); }

    void push(const T& x) {
        T acc = back_stack.empty() ? x : op(back_stack.back().second, x);
        back_stack.push_back({x, acc});
    }

    void pop() {
        if (front_stack.empty()) {
            while (!back_stack.empty()) {
                T x = back_stack.back().first;
                back_stack.pop_back();
                T acc = front_stack.empty() ? x : op(x, front_stack.back().second);
                front_stack.push_back({x, acc});
            }
        }
        assert(!front_stack.empty());
        front_stack.pop_back();
    }

    T fold() const {
        assert(!empty());
        if (front_stack.empty()) return back_stack.back().second;
        if (back_stack.empty()) return front_stack.back().second;
        return op(front_stack.back().second, back_stack.back().second);
    }
};

