#include <algorithm>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct Point {
  int x, y;
};

class Solver {
public:
  int N, M, K, T;
  vector<vector<int>> adj;
  vector<Point> coords;
  vector<vector<int>> dist_matrix;

  // State for a single simulation run
  int current_pos;
  int last_pos;
  string hand;
  vector<set<string>> shop_inventories;
  vector<char> tree_flavors;

  int current_step_count;
  vector<int> tree_last_visit;
  vector<int> visit_counts;
  vector<char> target_flavors; // Current target configuration

  // Output buffer
  vector<int> move_log;

  Solver() {}

  void read_input() {
    if (!(cin >> N >> M >> K >> T))
      return;
    adj.assign(N, vector<int>());
    for (int i = 0; i < M; ++i) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    coords.resize(N);
    for (int i = 0; i < N; ++i) {
      cin >> coords[i].x >> coords[i].y;
    }

    // Precompute distances
    dist_matrix.assign(N, vector<int>(N, 1e9));
    for (int i = 0; i < N; ++i) {
      queue<int> q;
      q.push(i);
      dist_matrix[i][i] = 0;
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
          if (dist_matrix[i][v] > dist_matrix[i][u] + 1) {
            dist_matrix[i][v] = dist_matrix[i][u] + 1;
            q.push(v);
          }
        }
      }
    }
  }

  // Reset state for a new simulation with specific target flavors
  void init(const vector<char> &targets) {
    current_pos = 0;
    last_pos = -1;
    hand = "";
    shop_inventories.assign(K, set<string>());
    tree_flavors.assign(N, 'W');
    target_flavors = targets;

    move_log.clear();
    current_step_count = 0;
    tree_last_visit.assign(N, -100);
    visit_counts.assign(N, 0);
    current_path.clear(); // Fix: Clear leftover path from previous run
  }

  // Returns {score, move_log}
  // Score = Total distinct strings delivered
  pair<int, vector<int>> solve() {
    int delivered_count = 0;

    for (int step = 0; step < T; ++step) {
      current_step_count = step;
      if (current_path.empty()) {
        find_new_path();
      }

      if (!current_path.empty()) {
        int next_v = current_path.front();
        current_path.pop_front();

        if (next_v == -1) {
          record_move(-1);
          tree_flavors[current_pos] = 'R';
        } else {
          if (move_to(next_v)) {
            delivered_count++;
          }
        }
      } else {
        random_walk();
      }
    }
    return {delivered_count, move_log};
  }

private:
  deque<int> current_path;

  struct BFSState {
    int u;
    int prev_u;
    string s;
    vector<int> seq;
  };

  void find_new_path() {
    // Strategy: Shortest Unique Path (BFS)
    queue<BFSState> q;
    q.push({current_pos, last_pos, hand, {}});

    set<pair<int, string>> visited;
    visited.insert({current_pos, hand});

    bool found = false;
    int MAX_DEPTH = 10;

    while (!q.empty()) {
      BFSState st = q.front();
      q.pop();

      // Check delivery condition
      if (st.u < K) {
        // Must have non-empty string and be unique
        if (!st.s.empty() && shop_inventories[st.u].count(st.s) == 0) {
          for (int m : st.seq)
            current_path.push_back(m);
          found = true;
          break;
        }
      }

      // Depth limit (based on path length)
      if (st.seq.size() >= MAX_DEPTH)
        continue;

      vector<int> neighbors = adj[st.u];
      if (neighbors.size() > 1) {
        // Random shuffle to avoid bias
        int r = rand() % neighbors.size();
        swap(neighbors[0], neighbors[r]);
      }

      for (int v : neighbors) {
        if (v == st.prev_u)
          continue; // No U-Turn

        // Prevent revisiting any node in the current path sequence
        // This avoids the complex issue of state tracking (double flipping
        // W->R)
        bool visited_in_path = false;
        for (int visited_node : st.seq) {
          if (visited_node == v) {
            visited_in_path = true;
            break;
          }
        }
        if (visited_in_path)
          continue;

        // Calculate new state
        string next_s = st.s;
        vector<int> next_seq = st.seq;
        next_seq.push_back(v); // Move FIRST

        if (v >= K) { // Tree
          char flavor = tree_flavors[v];
          next_s += flavor; // Collect CURRENT flavor

          // If we want this to be R but it is W, flip it AFTER arrival
          // so that NEXT time we visit (in a future path), it will be R.
          if (flavor == 'W' && target_flavors[v] == 'R') {
            next_seq.push_back(-1); // Change flavor action
          }
        }

        // Pruning
        if (visited.count({v, next_s}))
          continue;
        visited.insert({v, next_s});

        q.push({v, st.u, next_s, next_seq});
      }
    }

    if (!found) {
      random_walk();
    }
  }

  vector<int> construct_path(int start, int goal, int forbidden_first_move) {
    if (start == goal)
      return {};

    vector<int> parent(N, -2);
    vector<int> dist(N, 1e9);
    queue<int> bfs_q;

    parent[start] = -1;
    dist[start] = 0;
    bfs_q.push(start);

    bool found = false;
    while (!bfs_q.empty()) {
      int u = bfs_q.front();
      bfs_q.pop();
      if (u == goal) {
        found = true;
        break;
      }

      for (int v : adj[u]) {
        if (u == start && v == forbidden_first_move)
          continue;
        if (dist[v] > dist[u] + 1) {
          dist[v] = dist[u] + 1;
          parent[v] = u;
          bfs_q.push(v);
        }
      }
    }

    if (!found)
      return {};
    vector<int> path;
    int curr = goal;
    while (curr != start) {
      path.push_back(curr);
      curr = parent[curr];
    }
    reverse(path.begin(), path.end());
    return path;
  }

  void random_walk() {
    vector<int> candidates;
    for (int v : adj[current_pos]) {
      if (v != last_pos)
        candidates.push_back(v);
    }
    if (candidates.empty()) {
      if (last_pos != -1)
        move_to(last_pos);
      else if (!adj[current_pos].empty())
        move_to(adj[current_pos][0]);
    } else {
      int next_v = candidates[rand() % candidates.size()];
      move_to(next_v);
    }
  }

  // Returns true if delivery happened
  bool move_to(int v) {
    record_move(v);
    last_pos = current_pos;
    current_pos = v;
    visit_counts[v]++;

    if (current_pos < K) {
      bool is_new = shop_inventories[current_pos].find(hand) ==
                    shop_inventories[current_pos].end();
      shop_inventories[current_pos].insert(hand);
      hand = "";
      return is_new;
    } else {
      hand += tree_flavors[current_pos];
      tree_last_visit[current_pos] = current_step_count;
      return false;
    }
  }

  void record_move(int m) { move_log.push_back(m); }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solver solver;
  solver.read_input();

  // Hill Climbing Parameters
  double TIME_LIMIT = 1.8; // seconds
  clock_t start_time = clock();

  // Initial Solution
  vector<char> current_target_flavors(solver.N, 'W');
  for (int i = solver.K; i < solver.N; ++i) {
    if (rand() % 100 < 50)
      current_target_flavors[i] = 'R';
  }

  solver.init(current_target_flavors);
  auto [best_score, best_log] = solver.solve();

  // Optimization Loop
  while ((double)(clock() - start_time) / CLOCKS_PER_SEC < TIME_LIMIT) {
    // Create neighbor: Flip one tree flavor
    vector<char> next_target_flavors = current_target_flavors;
    int flip_idx = solver.K + rand() % (solver.N - solver.K);
    next_target_flavors[flip_idx] =
        (next_target_flavors[flip_idx] == 'W' ? 'R' : 'W');

    // Evaluate
    solver.init(next_target_flavors);
    auto [score, log] = solver.solve();

    // Accept if better or equal (to allow plateau traversal)
    if (score >= best_score) {
      best_score = score;
      best_log = log;
      current_target_flavors = next_target_flavors;
    }
  }

  // Output best result
  for (int move : best_log) {
    cout << move << "\n";
  }

  return 0;
}