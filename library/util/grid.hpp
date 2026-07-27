#pragma once

#include <array>
#include <cassert>
#include <cstddef>
#include <queue>
#include <stack>
#include <utility>
#include <vector>

constexpr std::array<int, 4> di4 = {-1, 0, 1, 0};
constexpr std::array<int, 4> dj4 = {0, 1, 0, -1};
constexpr std::array<int, 8> di8 = {-1, -1, -1, 0, 0, 1, 1, 1};
constexpr std::array<int, 8> dj8 = {-1, 0, 1, -1, 1, -1, 0, 1};

constexpr bool in_grid(int i, int j, int h, int w) {
  return 0 <= i && i < h && 0 <= j && j < w;
}

template <std::size_t K, class Passable>
std::vector<std::vector<int>> grid_bfs(int h, int w, int si, int sj, Passable passable,
                                       const std::array<int, K>& di,
                                       const std::array<int, K>& dj) {
  assert(h >= 0 && w >= 0);
  assert(in_grid(si, sj, h, w));

  std::vector<std::vector<int>> dist(h, std::vector<int>(w, -1));
  if (!passable(si, sj)) return dist;

  std::queue<std::pair<int, int>> que;
  dist[si][sj] = 0;
  que.push({si, sj});

  while (!que.empty()) {
    auto [i, j] = que.front();
    que.pop();
    for (std::size_t dir = 0; dir < K; dir++) {
      int ni = i + di[dir];
      int nj = j + dj[dir];
      if (!in_grid(ni, nj, h, w)) continue;
      if (!passable(ni, nj)) continue;
      if (dist[ni][nj] != -1) continue;
      dist[ni][nj] = dist[i][j] + 1;
      que.push({ni, nj});
    }
  }
  return dist;
}

template <class Passable>
std::vector<std::vector<int>> grid_bfs(int h, int w, int si, int sj, Passable passable) {
  return grid_bfs(h, w, si, sj, passable, di4, dj4);
}

template <std::size_t K, class Passable>
std::vector<std::vector<bool>> grid_dfs(int h, int w, int si, int sj, Passable passable,
                                        const std::array<int, K>& di,
                                        const std::array<int, K>& dj) {
  assert(h >= 0 && w >= 0);
  assert(in_grid(si, sj, h, w));

  std::vector<std::vector<bool>> seen(h, std::vector<bool>(w));
  if (!passable(si, sj)) return seen;

  std::stack<std::pair<int, int>> st;
  seen[si][sj] = true;
  st.push({si, sj});

  while (!st.empty()) {
    auto [i, j] = st.top();
    st.pop();
    for (std::size_t dir = 0; dir < K; dir++) {
      int ni = i + di[dir];
      int nj = j + dj[dir];
      if (!in_grid(ni, nj, h, w)) continue;
      if (!passable(ni, nj)) continue;
      if (seen[ni][nj]) continue;
      seen[ni][nj] = true;
      st.push({ni, nj});
    }
  }
  return seen;
}

template <class Passable>
std::vector<std::vector<bool>> grid_dfs(int h, int w, int si, int sj, Passable passable) {
  return grid_dfs(h, w, si, sj, passable, di4, dj4);
}
