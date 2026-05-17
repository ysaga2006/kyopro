#pragma once

#include <bits/stdc++.h>
using namespace std;

struct Lca {
    int n;
    int lg;
    vector<int> depth;
    vector<vector<int>> up;
    vector<vector<int>> g;

    explicit Lca(int n_) : n(n_), lg(1), depth(n), g(n) {
        while ((1 << lg) <= n) lg++;
        up.assign(lg, vector<int>(n, -1));
    }

    void add_edge(int a, int b) {
        g[a].push_back(b);
        g[b].push_back(a);
    }

    void build(int root = 0) {
        dfs(root, -1);
        for (int k = 0; k + 1 < lg; k++) {
            for (int v = 0; v < n; v++) {
                if (up[k][v] != -1) up[k + 1][v] = up[k][up[k][v]];
            }
        }
    }

    int jump(int v, int d) const {
        for (int k = 0; k < lg; k++) {
            if ((d >> k) & 1) v = up[k][v];
            if (v == -1) break;
        }
        return v;
    }

    int query(int a, int b) const {
        if (depth[a] < depth[b]) swap(a, b);
        a = jump(a, depth[a] - depth[b]);
        if (a == b) return a;
        for (int k = lg - 1; k >= 0; k--) {
            if (up[k][a] != up[k][b]) {
                a = up[k][a];
                b = up[k][b];
            }
        }
        return up[0][a];
    }

    int dist(int a, int b) const {
        int c = query(a, b);
        return depth[a] + depth[b] - 2 * depth[c];
    }

  private:
    void dfs(int v, int p) {
        up[0][v] = p;
        for (int to : g[v]) {
            if (to == p) continue;
            depth[to] = depth[v] + 1;
            dfs(to, v);
        }
    }
};

