# 競プロ用 C++ ライブラリ

このフォルダは、AtCoder Library (ACL) を前提にした競プロ用テンプレートと補助ライブラリです。

ACL に入っている `dsu`, `fenwick_tree`, `segtree`, `lazy_segtree`, `modint`, `scc_graph`, `maxflow`, `mincostflow`, `two_sat` などは基本的に ACL を使い、このライブラリでは ACL にないものや、毎回書くのが面倒な小物を整備します。

## 基本方針

- 整数は基本的に `ll` (`long long`) を使う
- ACL にあるものは再実装しない
- 提出用テンプレートは小さく保つ
- デバッグ出力は `-DLOCAL` の時だけ有効にする
- ライブラリは `library/...` から include する

フォルダ構成や practice の命名規則は [docs/structure.md](docs/structure.md) にまとめています。
自分用の競プロメモは [docs/tips.md](docs/tips.md) に置いています。

## フォルダ構成

```txt
kyopro/
  template/
    main.cpp              # 普段使いの提出テンプレート
    local_compile.sh      # ローカル確認用コンパイルスクリプト

  library/
    util/
      basic.hpp           # 型エイリアス、定数、chmin/chmax など
      debug.hpp           # ローカル専用 debug(...)
      compress.hpp        # 座標圧縮
      grid.hpp            # グリッド方向配列

    math/
      combination.hpp     # ACL modint 用の組合せ
      sieve.hpp           # 素数判定、素因数分解、約数列挙

    graph/
      dijkstra.hpp        # ダイクストラ法
      zero_one_bfs.hpp    # 0-1 BFS
      lca.hpp             # 木の LCA

    dp/
      lis.hpp             # LIS 長
      swag.hpp            # Sliding Window Aggregation

  verify/
    smoke.cpp             # 簡易動作確認
```

## テンプレート

`template/main.cpp` が基本テンプレートです。

```cpp
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#include "library/util/basic.hpp"
#include "library/util/debug.hpp"
```

`abc/setup` や `awc/setup_contest.sh` で作る `main.cpp` は、このテンプレートをコピーします。

## コンパイル

ローカルで簡単に確認する場合:

```sh
cd /Users/sagarayuto/kyopro
./template/local_compile.sh verify/smoke.cpp
```

このスクリプトは以下を付けてコンパイルします。

```sh
-DLOCAL
-I/Users/sagarayuto/kyopro
-I/Users/sagarayuto/kyopro/vendor/ac-library
```

`-DLOCAL` が付くので、`debug(...)` が有効になります。

## util/basic.hpp

基本的な型、定数、小関数をまとめています。

```cpp
using ll = long long;
using ull = unsigned long long;
using ld = long double;

constexpr int INF_INT = 1'000'000'000;
constexpr ll INF = 4'000'000'000'000'000'000LL;
constexpr ld EPS = 1e-12L;
constexpr ll MOD = 998244353LL;
constexpr ll MOD1 = 1'000'000'007LL;
constexpr ll MOD9 = 998244353LL;
```

### chmin / chmax

更新が起きたかを `bool` で返します。

```cpp
ll ans = INF;
if (chmin(ans, x)) {
    // ans が更新された時だけ行う処理
}
```

### floor_div / ceil_div

負数にも対応した床除算・天井除算です。

```cpp
floor_div(-3LL, 2LL); // -2
ceil_div(-3LL, 2LL);  // -1
```

### argsort

配列をソートした時の添字順を返します。

```cpp
vector<ll> a = {30, 10, 20};
auto p = argsort(a); // {1, 2, 0}
```

## util/debug.hpp

`debug(...)` を使うためのヘッダです。

```cpp
int x = 3;
vector<int> v = {1, 4, 1, 5};
debug(x, v);
```

`-DLOCAL` 付きでコンパイルした時だけ、標準エラーに出力されます。

```txt
[x, v] = 3, {1, 4, 1, 5}
```

提出時に `-DLOCAL` を付けなければ、`debug(...)` は何もしません。消し忘れても答えの出力には混ざりません。

対応している主な型:

- `int`, `ll`, `string`, `bool` など通常の出力可能な型
- `pair`
- `tuple`
- `vector`, `set`, `map` など range-for できる型

ループ中に置くと、その行を通るたびに値が見えます。

```cpp
for (int i = 0; i < n; i++) {
    cur += a[i];
    if (i < 10) debug(i, cur);
}
```

## util/compress.hpp

座標圧縮です。

```cpp
vector<ll> xs = {100, 50, 100, 20};
Compress<ll> comp(xs);

int id = comp.get(100); // 圧縮後の番号
ll original = comp[id]; // 元の値
int m = comp.size();    // 異なる値の個数
```

値を後から追加する場合:

```cpp
Compress<ll> comp;
comp.add(x);
comp.add(vector<ll>{a, b, c});
comp.build();
```

`get(x)` は `x` が登録済みである前提で使うのが基本です。

## util/grid.hpp

グリッド探索用の方向配列です。

```cpp
for (int dir = 0; dir < 4; dir++) {
    int ni = i + di4[dir];
    int nj = j + dj4[dir];
}
```

用意しているもの:

- `di4`, `dj4`: 上右下左の4近傍
- `di8`, `dj8`: 8近傍

## math/combination.hpp

ACL の `modint` と一緒に使う組合せ計算です。

```cpp
using mint = modint998244353;

Combination<mint> comb;
mint x = comb.comb(n, r); // nCr
mint y = comb.perm(n, r); // nPr
```

内部で階乗と逆元階乗を必要なところまで自動で伸ばします。

使える主な関数:

- `fac(n)`: `n!`
- `invfac(n)`: `(n!)^{-1}`
- `comb(n, r)`: `nCr`
- `perm(n, r)`: `nPr`

`r < 0` や `r > n` の場合、`comb` と `perm` は `0` を返します。

## math/sieve.hpp

線形篩です。`1..n` の素数判定、素因数分解、約数列挙ができます。

```cpp
Sieve sieve(1'000'000);

bool ok = sieve.is_prime(97);
auto pf = sieve.factorize(84); // {{2, 2}, {3, 1}, {7, 1}}
auto ds = sieve.divisors(84);  // 約数を昇順で返す
```

`factorize(x)` と `divisors(x)` は `1 <= x <= n` の範囲で使います。

## graph/dijkstra.hpp

非負重みグラフの最短路です。

```cpp
Dijkstra<ll> g(n);
g.add_edge(u, v, w);       // 有向辺
g.add_edge(u, v, w, true); // 無向辺

auto dist = g.solve(s);
```

注意:

- 辺重みは非負であること
- 到達不能距離はデフォルトで `numeric_limits<Cost>::max() / 4`
- `Cost` は基本的に `ll` 推奨

## graph/zero_one_bfs.hpp

辺重みが `0` または `1` のグラフの最短路です。

```cpp
ZeroOneBfs g(n);
g.add_edge(u, v, 0);
g.add_edge(x, y, 1, true);

auto dist = g.solve(s);
```

通常のダイクストラより軽く、`O(N + M)` で動きます。

## graph/lca.hpp

木の最近共通祖先です。

```cpp
Lca lca(n);
for (...) {
    lca.add_edge(u, v);
}
lca.build(0);

int c = lca.query(a, b);
int d = lca.dist(a, b);
```

使える主な関数:

- `build(root)`: 根を決めて前計算
- `query(a, b)`: `a` と `b` の LCA
- `dist(a, b)`: 木上距離
- `jump(v, d)`: `v` から `d` 個親へ上がる

注意:

- 入力は木である前提
- 現在の実装は DFS 再帰なので、頂点数が非常に大きい場合は再帰深さに注意

## dp/lis.hpp

LIS の長さを返します。

```cpp
vector<ll> a = {3, 1, 2, 1, 8};
int len = lis_length(a);        // 狭義増加
int len2 = lis_length(a, false); // 広義増加
```

計算量は `O(N log N)` です。

## dp/swag.hpp

Sliding Window Aggregation です。キューのように `push` / `pop` しながら、全体の畳み込みを高速に取れます。

演算は結合的である必要があります。単位元は持たない設計なので、空の状態で `fold()` は呼べません。

```cpp
int op_sum(int a, int b) {
    return a + b;
}

Swag<int, op_sum> swag;
swag.push(1);
swag.push(2);
swag.push(3);

int s = swag.fold(); // 6
swag.pop();
s = swag.fold();     // 5
```

典型用途:

- 固定長区間の最大値・最小値・和
- 尺取り中の区間集約
- 交換法則は不要だが、結合法則は必要な演算

## verify/smoke.cpp

今あるライブラリを軽くコンパイル・実行確認するためのファイルです。

```sh
./template/local_compile.sh verify/smoke.cpp
```

成功すると、`debug(...)` の出力と `smoke ok` が標準エラーに出ます。

## ACL について

この環境では ACL 本体が以下にあります。

```txt
/Users/sagarayuto/kyopro/vendor/ac-library
```

ローカルコンパイル時は include パスにこれを追加します。

```sh
-I/Users/sagarayuto/kyopro/vendor/ac-library
```

AtCoder 以外のジャッジに ACL を使って提出したい場合は、基本的に単一ファイルへ展開して提出します。

```sh
cd /Users/sagarayuto/kyopro
python3 vendor/ac-library/expander.py main.cpp > combined.cpp
```

## 今後追加すると良さそうなもの

- `rerooting.hpp`: 全方位木 DP
- `lowlink.hpp`: 橋・関節点
- `topological_sort.hpp`
- `run_length.hpp`
- `matrix.hpp`
- `rollback_dsu.hpp`
- include 展開用の `bundle.py`
