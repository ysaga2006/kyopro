# kyopro フォルダ構成ルール

この文書は、`kyopro` フォルダを長く使うための整理ルールです。

目的は、あとから見たときに「これは本番の記録なのか」「練習で解いたものなのか」「共通ライブラリなのか」がすぐ分かるようにすることです。

## 一番大事なルール

コードの置き場所は、問題の出典ではなく **解いた目的** で決めます。

- 本番コンテストとして参加したもの: `contests/`
- 後日練習・復習・弱点補強として解いたもの: `practice/`
- 共通で使うテンプレートやライブラリ: `template/`, `library/`
- 外部依存やツール: `vendor/`, `tools/`
- もう普段は見ないが残したいもの: `archive/`

たとえば ABC の過去問を練習として解くなら、出典は ABC でも `practice/` に置きます。

```txt
practice/atcoder/abc/abc350/c.cpp
```

一方、ABC にリアルタイム参加して作ったコードは `contests/` に置きます。

```txt
contests/atcoder/abc/abc430/a/main.cpp
```

同じ問題を本番でも解いて、後で復習した場合は、両方にあって構いません。

```txt
contests/atcoder/abc/abc430/e/main.cpp   # 本番時のコード
practice/atcoder/abc/abc430/e.cpp        # 復習で書き直したコード
```

これは重複ではなく、時点の違う記録として扱います。

## 理想の全体構成

将来的には、次のような構成を目指します。

```txt
kyopro/
  README.md
  .clang-format
  .gitignore
  .vscode/

  docs/
    structure.md

  template/
    main.cpp
    local_compile.sh

  library/
    util/
    math/
    graph/
    dp/

  verify/
    smoke.cpp

  contests/
    atcoder/
      abc/
      arc/
      ahc/
      awc/
    codeforces/

  practice/
    atcoder/
      abc/
      arc/
      dp-contest/
      tenkei90/
    aoj/
    codeforces/
    others/

  tools/
    setup_abc
    setup_awc
    bundle.py

  vendor/
    ac-library/

  archive/
```

今すぐ全移動する必要はありません。まずは新しく作るものからこのルールに寄せていき、既存フォルダは必要になったタイミングで少しずつ移します。

## contests のルール

`contests/` は、本番コンテストの作業ログです。

### AtCoder ABC / ARC

```txt
contests/atcoder/abc/abc430/a/main.cpp
contests/atcoder/abc/abc430/b/main.cpp
contests/atcoder/arc/arc180/a/main.cpp
```

基本は1問1フォルダにして、`main.cpp` と `input.txt` を置きます。

```txt
abc430/
  a/
    main.cpp
    input.txt
  b/
    main.cpp
    input.txt
```

理由:

- setup スクリプトと相性がよい
- 問題ごとの入力・実行ファイル・メモを置きやすい
- 本番中の作業単位と一致する

### AHC / AWC

AHC や AWC も本番参加なら `contests/atcoder/` に寄せます。

```txt
contests/atcoder/ahc/ahc060/main.cpp
contests/atcoder/awc/awc0040/a/main.cpp
```

AWC は5問構成なので、setup で作る問題は `a` から `e` までです。

```txt
awc0040/
  a/
  b/
  c/
  d/
  e/
```

### Codeforces

本番参加なら `contests/codeforces/` に置きます。

```txt
contests/codeforces/round_1076/a.cpp
contests/codeforces/round_1076/b.cpp
```

Codeforces は1問1ファイルでも十分です。入力やメモを分けたい場合だけ問題フォルダにします。

## practice のルール

`practice/` は練習・復習・埋め直し用です。

ここは「あとで探しやすいこと」を優先します。本番時のフォルダ構造を完全に再現する必要はありません。

### AtCoder ABC の過去問

ABC の過去問を練習として解く場合:

```txt
practice/atcoder/abc/abc350/c.cpp
practice/atcoder/abc/abc350/d.cpp
practice/atcoder/abc/abc400/e.cpp
```

1問1ファイルを基本にします。

理由:

- practice では入力ファイルやビルド成果物を問題ごとに分ける必要が薄い
- 一覧した時に「どの問題を解いたか」が分かりやすい
- 本番用の `contests/.../a/main.cpp` と役割が分かれる

必要が出た場合だけ、問題フォルダにしても構いません。

```txt
practice/atcoder/abc/abc350/c/
  main.cpp
  note.md
  input.txt
```

判断基準:

- ただ解くだけ: `c.cpp`
- 解説メモや複数実装を残したい: `c/`
- 乱択テストや生成器がある: `c/`

### ARC の過去問

```txt
practice/atcoder/arc/arc180/a.cpp
practice/atcoder/arc/arc180/b.cpp
```

ABC と同じく、基本は1問1ファイルです。

### Educational / 典型系

コンテスト名や教材名でまとめます。

```txt
practice/atcoder/dp-contest/a.cpp
practice/atcoder/dp-contest/b.cpp
practice/atcoder/tenkei90/001.cpp
practice/atcoder/tenkei90/002.cpp
```

典型90のように番号が3桁で管理されているものは、ゼロ埋めします。

```txt
001.cpp
042.cpp
090.cpp
```

### AOJ

AOJ は問題IDをそのまま使います。

```txt
practice/aoj/ITP1_3_D.cpp
practice/aoj/ALDS1_1_A.cpp
practice/aoj/GRL_1_A.cpp
```

既存ファイルに `ITP_3_D.cpp` のような名前がある場合、新規作成分から公式ID寄せにしていけば十分です。

### Codeforces 練習

Codeforces の練習は、コンテスト番号と問題文字を入れます。

```txt
practice/codeforces/1076/a.cpp
practice/codeforces/1076/b.cpp
```

問題名まで入れたい場合は、短くします。

```txt
practice/codeforces/1076/a_minimizing_the_string.cpp
```

ただし、長いファイル名は探しにくくなるので、基本は `a.cpp`, `b.cpp` でよいです。

## practice 内の命名規則

基本ルール:

- ファイル名は小文字中心
- AtCoder ABC/ARC は `a.cpp`, `b.cpp`, `c.cpp`
- 典型90など番号管理のものは `001.cpp`
- AOJ は公式IDを使う
- 1問1ファイルを基本にする
- メモや生成器が必要な時だけ1問1フォルダにする

推奨:

```txt
practice/atcoder/abc/abc350/c.cpp
practice/atcoder/tenkei90/001.cpp
practice/aoj/ALDS1_1_A.cpp
practice/codeforces/1076/a.cpp
```

避けたいもの:

```txt
practice/abc350C.cpp
practice/ABC350/c_ans.cpp
practice/atcoder/abc350-c.cpp
```

理由:

- 大文字小文字や区切りが揺れる
- コンテスト単位で一覧しづらい
- 後でスクリプト化しにくい

## template / library / verify

### template

`template/` は提出用テンプレートです。

```txt
template/main.cpp
template/local_compile.sh
```

setup スクリプトは `template/main.cpp` をコピーします。

### library

`library/` は共通ライブラリです。

```txt
library/util/
library/math/
library/graph/
library/dp/
```

ACL にあるものは原則として置きません。ACL にないもの、または ACL を使いやすくする薄い補助だけ置きます。

### verify

`verify/` はライブラリの動作確認用です。

```txt
verify/smoke.cpp
```

新しいライブラリを追加したら、最低限 `smoke.cpp` に小さな確認を足します。

## tools / vendor / archive

### tools

自分で使うスクリプトを置きます。

```txt
tools/setup_abc
tools/setup_awc
tools/bundle.py
```

現在は `tools/setup_abc` と `tools/setup_awc` を本体にし、古い `abc/setup` と `awc/setup_contest.sh` は互換用のラッパーとして残しています。

### vendor

外部から持ってきた依存を置きます。

```txt
vendor/ac-library/
```

ACL は `vendor/ac-library` に置きます。コンパイル時の include パスもこの場所を向けます。

### archive

普段使わないが、すぐ消すのは不安なものを置きます。

```txt
archive/atcoder-novisteps-sync/
archive/old-settings/
```

`.claude` や古い `.vscode`、古いテンプレートなどは、削除前に一度ここへ逃がすと安全です。

## 設定ファイルの方針

### .clang-format

原則としてルートの `.clang-format` だけを使います。

```txt
kyopro/.clang-format
```

各フォルダに `.clang-format` が散っていると、どの設定が効いているか分かりにくくなります。特別な理由がない限り、下位フォルダの `.clang-format` は整理候補です。

### .vscode

基本はルートの `.vscode` に寄せます。

ただし、`abc/` や `practice/` を単体で VS Code で開く習慣がある場合、そのフォルダの `.vscode` を残す意味はあります。

判断基準:

- `kyopro` 全体を開く: ルート `.vscode` だけでよい
- `abc` だけ開くことが多い: `abc/.vscode` を残してもよい
- ほぼ使っていない: `archive/` へ移す候補

### .DS_Store

`.DS_Store` は macOS が自動生成するファイルなので、基本的に Git 管理しません。

`.gitignore` に以下を入れておくとよいです。

```gitignore
.DS_Store
**/.DS_Store
build/
*.out
```

## 移行の進め方

いきなり全てを移動すると、setup スクリプトや VS Code 設定、Git 管理の境界が壊れやすいです。

おすすめの順番:

1. 新しく作る practice コードから命名規則を適用する
2. `README.md` と `docs/structure.md` を運用の基準にする
3. `.clang-format` をルートへ寄せる
4. 使っていない `.DS_Store`, build 成果物を整理する
5. setup スクリプトを `tools/` に集約する
6. 既存の `abc`, `arc`, `ahc`, `awc` を `contests/` 配下へ移す

特に `abc`, `awc`, `ahc`, `practice`, `codeforces` はそれぞれ `.git` を持っているため、移動時は Git 管理の扱いを確認してから進めます。

## 迷った時の判断

迷ったら次の基準で決めます。

- 本番中に作った: `contests/`
- 後から練習で解いた: `practice/`
- 何度も使う部品: `library/`
- 提出の土台: `template/`
- ライブラリ確認: `verify/`
- スクリプト: `tools/`
- 外部から持ってきたもの: `vendor/`
- 今は使わないが残したい: `archive/`
