#pragma once

#include <bits/stdc++.h>
using namespace std;

struct ZeroOneBfs {
    struct Edge {
        int to;
        int cost;
    };

    int n;
    vector<vector<Edge>> g;

    explicit ZeroOneBfs(int n_) : n(n_), g(n) {}

    void add_edge(int from, int to, int cost, bool undirected = false) {
        assert(cost == 0 || cost == 1);
        g[from].push_back({to, cost});
        if (undirected) g[to].push_back({from, cost});
    }

    vector<int> solve(int s, int inf = 1'000'000'000) const {
        vector<int> dist(n, inf);
        deque<int> que;
        dist[s] = 0;
        que.push_front(s);
        while (!que.empty()) {
            int v = que.front();
            que.pop_front();
            for (const auto& e : g[v]) {
                if (dist[e.to] > dist[v] + e.cost) {
                    dist[e.to] = dist[v] + e.cost;
                    if (e.cost == 0) que.push_front(e.to);
                    else que.push_back(e.to);
                }
            }
        }
        return dist;
    }
};

