#include <cstdlib>
#include <ctime>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

// 簡易ランダム入力生成
void generate_input() {
  int N = 100; // max inputs
  int M = 200;
  int K = 10;
  int T = 10000;

  cout << N << " " << M << " " << K << " " << T << endl;

  // Random edges (ensure connected-ish)
  set<pair<int, int>> edges;
  // minimal spanning tree-like structure
  for (int i = 1; i < N; ++i) {
    int p = rand() % i;
    edges.insert({p, i});
    cout << p << " " << i << endl;
  }
  // extra edges
  while (edges.size() < M) {
    int u = rand() % N;
    int v = rand() % N;
    if (u != v && u < v && edges.count({u, v}) == 0) {
      edges.insert({u, v});
      cout << u << " " << v << endl;
    }
  }

  // Coords
  for (int i = 0; i < N; ++i) {
    cout << rand() % 1000 << " " << rand() % 1000 << endl;
  }
}

int main(int argc, char *argv[]) {
  srand(time(NULL));
  generate_input();
  return 0;
}
