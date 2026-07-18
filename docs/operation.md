# kyopro 運用ガイド

この文書は、`kyopro` フォルダ全体の日々の使い方をまとめたものです。

対象:

- Git の使い方
- コミットメッセージの書き方
- コンテスト時の流れ
- 精進時の流れ
- ライブラリ・テンプレート・メモの更新
- VS Code / デバッグ / スニペットの扱い

## 基本方針

- `kyopro` はルート1つの Git リポジトリとして管理する
- Git 操作は必ず `/Users/sagarayuto/kyopro` で行う
- Git に入れるのはコード、設定、ドキュメント、ライブラリ、テンプレートだけ
- `input.txt`, `build/`, 実行ファイル, `.DS_Store`, `archive/` は Git に入れない
- 通常のコンテスト問題は、参加時期に関係なく出典に対応する `contests/` へ置く
- 教材・問題集・テーマ練習は `practice/` へ置く

## Git 操作をする場所

Git 操作は必ずここで行います。

```sh
cd /Users/sagarayuto/kyopro
```

確認:

```sh
git status
```

`contests/`, `practice/`, `library/` などの下位フォルダでは Git 操作しません。

現在は下位フォルダごとの `.git` は退避済みで、ルートの `.git` だけを使います。

```txt
kyopro/.git
```

古い Git 情報は Git 管理外の archive に置いています。

```txt
archive/old-git/
```

## Git に入れるもの

入れるもの:

- `.cpp`, `.hpp`
- `template/`
- `library/`
- `tools/`
- `verify/`
- `docs/`
- `README.md`
- `.clang-format`
- `.gitignore`
- `.vscode/` の設定ファイル
- `vendor/ac-library/atcoder/`
- `vendor/ac-library/expander.py`
- `vendor/ac-library/LICENSE`
- `vendor/ac-library/README.md`

入れないもの:

- `input.txt`
- `output.txt`
- `contest.acc.json`
- `build/`
- `test/`
- `*.out`
- `*.exe`
- `*.dSYM/`
- `tempCodeRunnerFile*`
- `.DS_Store`
- `archive/`
- ローカルに入った VS Code 拡張機能本体

## コミットのタイミング

基本は「意味のある単位」でコミットします。

おすすめ:

- コンテスト後に、そのコンテスト分をまとめてコミット
- 精進で数問解いたらまとめてコミット
- ライブラリを追加・修正したら単独コミット
- テンプレートや VS Code 設定を変えたら単独コミット
- ドキュメントを更新したら単独コミット

避けたいもの:

- 何日分もの解答・設定・ライブラリ更新を全部1コミットにする
- `input.txt` や実行ファイルを含める
- 途中で壊れている状態を理由なくコミットする

コンテスト中に細かくコミットする必要はありません。コンテスト後に落ち着いて確認してからで十分です。

## コミット前チェック

コミット前に見るもの:

```sh
git status --short
```

差分を見る:

```sh
git diff
git diff --staged
```

追加:

```sh
git add <file>
```

まとめて追加したい場合:

```sh
git add .
```

ただし `git add .` の後は、必ず `git status --short` で余計なものが入っていないか確認します。

コミット:

```sh
git commit -m "Add abc430 solutions"
```

## コミットメッセージ

英語で短く、命令形または名詞句で書きます。

基本形:

```txt
Add ...
Update ...
Fix ...
Move ...
Refactor ...
Document ...
```

例:

```txt
Add abc430 solutions
Add awc0040 solutions
Add dijkstra helper
Fix lca distance calculation
Update main template
Update VS Code debug input
Move tips into docs
Document kyopro operation
```

用途別:

```txt
Add abc431 solutions
Add practice dp-contest solutions
Add graph snippets
Fix debug printer for strings
Update setup scripts
Document folder structure
```

細かい書き方:

- 先頭は大文字
- 末尾のピリオドは付けない
- 1行で分かる内容にする
- `WIP` は基本使わない
- 日本語でも悪くはないが、今後は英語に寄せる

## コンテスト時の運用

### ABC / ARC

新規コンテストは `tools/setup_abc` を使います。

```sh
cd /Users/sagarayuto/kyopro
./sabc abc430
```

ARC の場合:

```sh
./sabc arc180
```

一部の問題だけ作る場合:

```sh
./sabc abc430 d e
```

生成先:

```txt
contests/atcoder/abc/abc430/a/main.cpp
contests/atcoder/abc/abc430/a/input.txt
```

ARC:

```txt
contests/atcoder/arc/arc180/a/main.cpp
```

### AWC

AWC は `tools/setup_awc` を使います。

```sh
cd /Users/sagarayuto/kyopro
./sawc 40
```

`awc0040` と書いてもよいです。

```sh
./sawc awc0040
```

AWC は5問構成なので、デフォルトで `a b c d e` を作ります。

一部だけ作る場合:

```sh
./sawc 40 d e
```

生成先:

```txt
contests/atcoder/awc/awc0040/a/main.cpp
contests/atcoder/awc/awc0040/a/input.txt
```

setup の本体は `tools/` にあります。普段は短い `./sabc` と `./sawc` を使うのが基本です。

## コンテスト中のデバッグ

VS Code で F5 を押すと、開いている `.cpp` と同じフォルダの `input.txt` を標準入力に使います。

```txt
main.cpp
input.txt
```

`input.txt` がない場合は、F5 のビルド前に空ファイルが自動作成されます。

### 複数テストケースをまとめて実行する

各問題フォルダの `test/` に入力を保存します。

```txt
test/
  01.in
  01.out
  02.in
  02.out
  03.in
  03.out
```

`.in` が入力、同じ番号の `.out` が期待出力です。`.out` が空なら、実行結果の表示だけを行います。

既存問題で `test/` がない場合は、最初の実行時に `01`〜`03` の雛形が自動作成されます。

リポジトリのルートから実行する場合:

```sh
./stest contests/atcoder/abc/abc430/a/main.cpp
```

VS Code では、対象の `main.cpp` を開いて「タスクの実行」から「複数テスト実行」を選べます。コンパイルは1回だけ行い、すべての `.in` をファイル名順に実行します。

典型90のように1フォルダに複数のソースがある場合は、ソース名ごとの`test/`を自動使用します。

```sh
./stest practice/tenkei90/032.cpp
```

この場合、テストの保存先は`practice/tenkei90/test/032/`です。`main.cpp`では従来どおり、同じ問題フォルダの`test/`を使います。

### ターミナルから短くテストする

グローバルコマンド`st`を使います。問題フォルダにいる場合は引数が要りません。

```sh
cd contests/atcoder/abc/abc430/a
st
```

コンテストフォルダにいる場合は問題記号だけを渡します。

```sh
cd contests/atcoder/abc/abc430
st a
```

どのフォルダにいても、コンテスト名と問題記号を指定できます。

```sh
st abc430 a
st 430 a
st arc180 a
st awc40 a
```

従来の`./stest <source.cpp>`も引き続き使えます。VS Codeでは「複数テスト実行」タスクを選べば、コマンド入力自体を省略できます。

`debug(...)` は `-DLOCAL` が付いている時だけ出力されます。F5 とローカルコンパイルでは有効です。

```cpp
debug(i, x, v);
```

提出時は `-DLOCAL` を付けないので、`debug(...)` は何もしません。

## コンテスト後の流れ

1. 余計な `input.txt`, `build/`, `.out` が Git に入らないことを確認する
2. 解答コードが残っていることを確認する
3. 必要なら `docs/tips.md` に反省やメモを書く
4. `git status --short` を見る
5. コミットする

例:

```sh
cd /Users/sagarayuto/kyopro
git status --short
git add contests/atcoder/abc/abc430 docs/tips.md
git commit -m "Add abc430 solutions"
```

## 精進時の運用

精進かどうかだけでは置き場所を変えません。

大事なルール:

- ABC・ARCなど通常のコンテスト過去問: `contests/`の対応する問題フォルダ
- 典型90・ADT・DP Contest・AOJなどの教材や問題集: `practice/`

ABC 過去問:

```txt
contests/atcoder/abc/abc350/c/main.cpp
```

ARC 過去問:

```txt
contests/atcoder/arc/arc180/a/main.cpp
```

典型90:

```txt
practice/tenkei90/001.cpp
```

AOJ:

```txt
practice/aoj/ALDS1_1_A.cpp
```

本番時のコードが既にある問題を解き直す場合は、通常は同じ`main.cpp`を更新します。変更前の実装はGit履歴に残ります。

## 精進コードのファイル名

基本:

- 問題記号で管理する教材: `a.cpp`, `b.cpp`, `c.cpp`
- 番号で管理する教材: `001.cpp`, `002.cpp`
- AOJ: 公式IDを使う
- 同じシリーズでは既存の命名規則を優先する

例:

```txt
practice/atcoder/dp-contest/c.cpp
practice/tenkei90/042.cpp
practice/aoj/ITP1_3_D.cpp
```

メモや生成器が必要な問題だけ、1問1フォルダにします。

```txt
practice/tenkei90/042/
  main.cpp
  note.md
  input.txt
```

## ライブラリ更新の運用

ライブラリは `library/` に置きます。

```txt
library/util/
library/math/
library/graph/
library/dp/
```

方針:

- ACL にあるものは原則として再実装しない
- ACL にないものを追加する
- ACL を使いやすくする薄い補助は置いてよい
- 新しいライブラリを追加したら、できるだけ `verify/smoke.cpp` に小さな確認を足す

確認:

```sh
./template/local_compile.sh verify/smoke.cpp
```

コミット例:

```txt
Add lowlink helper
Fix dijkstra unreachable distance
Update combination helper
```

## テンプレート更新の運用

提出用テンプレートはここです。

```txt
template/main.cpp
```

setup スクリプトはこのファイルをコピーします。

テンプレートを変更したら確認します。

```sh
./template/local_compile.sh template/main.cpp
```

コミット例:

```txt
Update main template
```

## スニペットの運用

既存のグローバル C++ スニペットはそのまま使います。

`kyopro` 専用の追加スニペットはここです。

```txt
.vscode/kyopro.code-snippets
```

追加済みの主な prefix:

```txt
main
rep
rrep
forr
sort
rsort
chmax
chmin
vec
vvin
grid
yn
debug
lambda
bin
bfs
pq
mint
comb
```

スニペット追加の方針:

- 短い定型句を中心にする
- 長いアルゴリズム実装はスニペットではなく `library/` に置く
- prefix は短く、覚えやすくする
- 既存 prefix と被らないようにする

## メモの運用

自分用の競プロメモはここです。

```txt
docs/tips.md
```

書くとよいもの:

- 間違えやすい実装メモ
- 解法の見方
- 典型の気づき
- コンテスト後の反省
- ライブラリ利用時の注意

長くなったら、テーマ別に分割して構いません。

```txt
docs/tips/graph.md
docs/tips/dp.md
docs/tips/math.md
```

## archive の扱い

`archive/` は Git 管理しません。

入っているもの:

- 古い Git 情報
- 古い VS Code 設定
- 古い AI ツール設定
- 普段使わないツール

必要になったら戻せますが、日常的には触らない置き場です。

## vendor の扱い

`vendor/` は外部依存を置く場所です。

現在は ACL を置いています。

```txt
vendor/ac-library/
```

Git 管理するのは、実戦で必要なものだけです。

- `vendor/ac-library/atcoder/`
- `vendor/ac-library/expander.py`
- `vendor/ac-library/LICENSE`
- `vendor/ac-library/README.md`

ACL 本体の中身は基本的に編集しません。

## よく使うコマンド

状態確認:

```sh
git status --short
```

直近ログ:

```sh
git log --oneline -5
```

スモークテスト:

```sh
./template/local_compile.sh verify/smoke.cpp
```

ABC セットアップ:

```sh
./sabc abc430
```

AWC セットアップ:

```sh
./sawc 40
```

## 迷った時

- ABCなど通常のコンテスト問題: 参加時期に関係なく `contests/`
- 教材・問題集・テーマ練習: `practice/`
- 何度も使う部品: `library/`
- 提出の土台: `template/`
- ライブラリ確認: `verify/`
- スクリプト: `tools/`
- 外部依存: `vendor/`
- 普段使わない退避物: `archive/`
- Git 操作: `/Users/sagarayuto/kyopro`

## テンプレート同期ルール

`template/main.cpp` を変更するときは、`.vscode/kyopro.code-snippets` の `main` スニペットも同じコミットで更新します。
