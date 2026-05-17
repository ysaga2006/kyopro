#pragma once

#include <bits/stdc++.h>
using namespace std;

namespace cp_debug {

template <class T, class = void>
struct is_iterable : false_type {};

template <class T>
struct is_iterable<T, void_t<decltype(begin(declval<T>())), decltype(end(declval<T>()))>>
    : true_type {};

template <>
struct is_iterable<string, void> : false_type {};

void print(const char* s) { cerr << '"' << s << '"'; }
void print(char c) { cerr << '\'' << c << '\''; }
void print(const string& s) { cerr << '"' << s << '"'; }
void print(bool x) { cerr << (x ? "true" : "false"); }

template <class T, class U>
void print(const pair<T, U>& p);

template <class... Ts>
void print(const tuple<Ts...>& t);

template <class T>
enable_if_t<!is_iterable<T>::value, void> print(const T& x) {
    cerr << x;
}

template <class T>
enable_if_t<is_iterable<T>::value, void> print(const T& xs) {
    cerr << "{";
    bool first = true;
    for (const auto& x : xs) {
        if (!first) cerr << ", ";
        first = false;
        print(x);
    }
    cerr << "}";
}

template <class T, class U>
void print(const pair<T, U>& p) {
    cerr << "(";
    print(p.first);
    cerr << ", ";
    print(p.second);
    cerr << ")";
}

template <class Tuple, size_t... Is>
void print_tuple_impl(const Tuple& t, index_sequence<Is...>) {
    ((cerr << (Is == 0 ? "" : ", "), print(get<Is>(t))), ...);
}

template <class... Ts>
void print(const tuple<Ts...>& t) {
    cerr << "(";
    print_tuple_impl(t, index_sequence_for<Ts...>{});
    cerr << ")";
}

void out() { cerr << '\n'; }

template <class Head, class... Tail>
void out(const Head& head, const Tail&... tail) {
    print(head);
    if constexpr (sizeof...(tail) > 0) {
        cerr << ", ";
        out(tail...);
    } else {
        cerr << '\n';
    }
}

}  // namespace cp_debug

#ifdef LOCAL
#define debug(...) \
    cerr << "[" << #__VA_ARGS__ << "] = ", ::cp_debug::out(__VA_ARGS__)
#else
#define debug(...) ((void)0)
#endif

