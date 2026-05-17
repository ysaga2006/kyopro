#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using mint = atcoder::modint998244353;

#include "../library/util/basic.hpp"
#include "../library/util/debug.hpp"
#include "../library/util/compress.hpp"
#include "../library/math/combination.hpp"
#include "../library/math/sieve.hpp"
#include "../library/graph/dijkstra.hpp"
#include "../library/graph/zero_one_bfs.hpp"
#include "../library/graph/lca.hpp"
#include "../library/dp/lis.hpp"
#include "../library/dp/swag.hpp"

int op_sum(int a, int b) { return a + b; }

int main() {
  static_assert(MOD == 998244353LL);
  static_assert(MOD1 == 1'000'000'007LL);
  static_assert(INF > (ll)3e18);
  static_assert(EPS < 1e-9L);

  vector<int> a = {3, 1, 4, 1, 5};
  debug(a);

  Compress<int> comp(a);
  assert(comp.size() == 4);
  assert(comp.get(4) == 2);

  Combination<mint> comb(10);
  assert(comb.comb(5, 2).val() == 10);

  Sieve sieve(100);
  assert(sieve.is_prime(97));
  assert((sieve.factorize(84) == vector<pair<int, int>>{{2, 2}, {3, 1}, {7, 1}}));

  Dijkstra<long long> dij(3);
  dij.add_edge(0, 1, 2);
  dij.add_edge(1, 2, 3);
  assert(dij.solve(0)[2] == 5);

  ZeroOneBfs zob(3);
  zob.add_edge(0, 1, 0);
  zob.add_edge(1, 2, 1);
  assert(zob.solve(0)[2] == 1);

  Lca lca(4);
  lca.add_edge(0, 1);
  lca.add_edge(1, 2);
  lca.add_edge(1, 3);
  lca.build();
  assert(lca.query(2, 3) == 1);
  assert(lca.dist(2, 3) == 2);

  assert(lis_length(vector<int>{3, 1, 2, 1, 8}) == 3);

  Swag<int, op_sum> swag;
  swag.push(1);
  swag.push(2);
  swag.push(3);
  assert(swag.fold() == 6);
  swag.pop();
  assert(swag.fold() == 5);

  cerr << "smoke ok\n";
}
