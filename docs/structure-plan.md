# kyopro 新構成案

この文書は、現在の `kyopro` フォルダを少しずつ整理するための移行計画です。

目的は、普段見る場所をすっきりさせつつ、既存のコード・Git履歴・セットアップスクリプトを壊さずに移行することです。

2026-05-17 時点で、主要な移行は実施済みです。旧 `abc/`, `awc/`, `ahc/`, `codeforces/` 配下のコードは `contests/` に、旧 `practice` の AtCoder 系精進コードは `practice/atcoder/` に移動しました。旧配置に残っていた設定や補助ファイルは `archive/old-layout/` に退避しています。

## 現状の課題

現在のルート直下には、用途の違うものが同じ階層に並んでいます。

```txt
abc/
ahc/
awc/
codeforces/
practice/
ac-library-master/
atcoder-novisteps-sync-main/
library/
template/
verify/
build/
.claude/
.vscode/
```

気になる点:

- `abc/` の中に `arc2xx/` があり、ABC と ARC が混ざっている
- `abc`, `ahc`, `awc`, `codeforces`, `practice` が同じ階層にあり、役割の粒度が揃っていない
- `ac-library-master` のような外部依存がルート直下に見えている
- `atcoder-novisteps-sync-main` のような普段使わないものがルート直下に見えている
- `.clang-format`, `.vscode`, `.claude` が複数階層に散っている
- `.DS_Store` や `build/` など、普段見る必要がないものが見えている
- `abc`, `ahc`, `awc`, `codeforces`, `practice` はそれぞれ `.git` を持っていて、移動時に Git 管理の扱いが必要

## 目指す完成形

最終的には、次の構成を目指します。

```txt
kyopro/
  README.md
  .gitignore
  .clang-format
  .vscode/

  docs/
    structure.md
    structure-plan.md

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
      acl-beginner-contest/
      others/
    aoj/
    codeforces/

  tools/
    setup_abc
    setup_awc
    bundle.py

  vendor/
    ac-library/

  archive/
    atcoder-novisteps-sync/
    old-settings/
```

## 役割

### docs

運用ルールや移行計画を置きます。

```txt
docs/structure.md       # 運用ルール
docs/structure-plan.md  # この移行計画
```

### template

提出コードの元になるテンプレートを置きます。

```txt
template/main.cpp
template/local_compile.sh
```

### library

ACL にないもの、または ACL を使いやすくする補助ライブラリを置きます。

```txt
library/util/
library/math/
library/graph/
library/dp/
```

### verify

ライブラリの動作確認コードを置きます。

```txt
verify/smoke.cpp
```

### contests

本番コンテストとして参加したコードを置きます。

```txt
contests/atcoder/abc/
contests/atcoder/arc/
contests/atcoder/ahc/
contests/atcoder/awc/
contests/codeforces/
```

### practice

後日練習・復習・弱点補強として解いたコードを置きます。

```txt
practice/atcoder/abc/
practice/atcoder/arc/
practice/atcoder/dp-contest/
practice/atcoder/tenkei90/
practice/aoj/
practice/codeforces/
```

ABC の過去問でも、練習として解くなら `practice/atcoder/abc/` に置きます。

### tools

セットアップや提出用ファイル生成など、自作スクリプトを置きます。

```txt
tools/setup_abc
tools/setup_awc
tools/bundle.py
```

### vendor

外部から持ってきた依存を置きます。

```txt
vendor/ac-library/
```

### archive

普段は使わないが、すぐ消すのは不安なものを置きます。

```txt
archive/atcoder-novisteps-sync/
archive/old-settings/
```

## 移行方針

一気に移すのではなく、壊れにくい順に進めます。

優先順位:

1. 新しく作るコードの置き場所を先に決める
2. ルート直下のノイズを減らす
3. 外部依存を `vendor/` に寄せる
4. セットアップスクリプトを `tools/` に寄せる
5. 既存コンテストコードを `contests/` に移す
6. Git 管理の境界を最後に整理する

## Phase 0: いま決める運用ルール

すぐに実施します。

- 新しく解く本番コンテストは `contests/` へ置く方針にする
- 新しく解く練習問題は `practice/` へ置く方針にする
- ABC 過去問を練習する場合は `practice/atcoder/abc/<contest>/<problem>.cpp`
- ARC 過去問を練習する場合は `practice/atcoder/arc/<contest>/<problem>.cpp`
- setup が生成するテンプレートは `template/main.cpp` を使う

既存フォルダはまだ動かしません。

## Phase 1: ルート直下の置き場を作る

まず、移行先の箱だけ作ります。

```txt
contests/
contests/atcoder/
contests/codeforces/
tools/
vendor/
archive/
```

この時点では中身を大きく動かさず、新規作成分だけ新構成へ寄せます。

期待する効果:

- 今後の置き場所で迷いにくくなる
- 既存の `abc/`, `awc/`, `practice/` を壊さずに運用を始められる

## Phase 2: 生成物と不要ファイルを見えにくくする

`.gitignore` を整備して、今後ノイズが増えないようにします。

候補:

```gitignore
.DS_Store
**/.DS_Store
build/
**/build/
*.out
*.dSYM/
tempCodeRunnerFile*
```

既存の `.DS_Store` や `build/` は、必要なければ削除候補です。

ただし、削除は Git 管理状況を確認してから行います。

## Phase 3: 設定ファイルを整理する

実施済みです。ルートの `.clang-format` と `.vscode/` を正とし、下位フォルダの設定は `archive/old-settings/` に退避しました。

### .clang-format

基本はルートの `.clang-format` だけを使います。

退避済み:

```txt
abc/.clang-format
ahc/.clang-format
awc/.clang-format
codeforces/.clang-format
practice/.clang-format
```

ACL 側の `.clang-format` は外部依存の一部なので、`vendor/ac-library/.clang-format` としてそのまま残しています。

### .vscode

基本はルートの `.vscode` に寄せます。

退避済み:

```txt
abc/.vscode/
ahc/.vscode/
awc/.vscode/
codeforces/.vscode/
practice/.vscode/
```

必要になった場合は `archive/old-settings/vscode/` から戻せます。

### .claude / CLAUDE.md / AGENTS.md

実施済みです。削除ではなく archive へ移しました。

退避済み:

```txt
.claude/
abc/.claude/
abc/CLAUDE.md
abc/AGENTS.md
awc/.claude/
practice/.claude/
```

移行先:

```txt
archive/old-settings/claude/
```

## Phase 4: ACL を vendor に移す

実施済みです。

移行前:

```txt
ac-library-master/
```

移行後:

```txt
vendor/ac-library/
```

修正済み:

- `template/local_compile.sh`
- `.vscode/tasks.json`
- `README.md`
- `docs/structure.md`

include パスは次のように変わります。

```sh
-I/Users/sagarayuto/kyopro/vendor/ac-library
```

注意:

- ACL は外部依存なので、移動だけにして中身は編集しない
- ACL 本体の中身は編集しない
- `expander.py` の参照先も更新する

## Phase 5: setup スクリプトを tools に移す

実施済みです。

移行前:

```txt
abc/setup
awc/setup_contest.sh
```

移行後:

```txt
tools/setup_abc
tools/setup_awc
```

setup の生成先も新構成に合わせます。

ABC:

```txt
contests/atcoder/abc/abc430/a/main.cpp
contests/atcoder/abc/abc430/b/main.cpp
```

ARC:

```txt
contests/atcoder/arc/arc180/a/main.cpp
```

AWC:

```txt
contests/atcoder/awc/awc0040/a/main.cpp
contests/atcoder/awc/awc0040/e/main.cpp
```

AWC は5問構成なので、デフォルト生成は `a b c d e` にします。

互換性のために、古い場所には薄いラッパーを残しています。

```sh
abc/setup -> ../tools/setup_abc を呼ぶだけ
awc/setup_contest.sh -> ../tools/setup_awc を呼ぶだけ
```

## Phase 6: contests へ既存コードを移す

ここが一番大きい移行です。

現在:

```txt
abc/abc0xx/
abc/abc1xx/
abc/abc2xx/
abc/abc3xx/
abc/abc4xx/
abc/arc2xx/
ahc/
awc/
codeforces/
```

移行後:

```txt
contests/atcoder/abc/abc0xx/
contests/atcoder/abc/abc1xx/
contests/atcoder/abc/abc2xx/
contests/atcoder/abc/abc3xx/
contests/atcoder/abc/abc4xx/
contests/atcoder/arc/arc2xx/
contests/atcoder/ahc/
contests/atcoder/awc/
contests/codeforces/
```

ただし、現在の `abc`, `ahc`, `awc`, `codeforces` はそれぞれ `.git` を持っています。

そのため、移動方法はどちらかを選びます。

### 案A: Git履歴をあまり気にせず、作業フォルダとして移す

単純にディレクトリを移動します。

メリット:

- 一番簡単
- フォルダ構成がすぐきれいになる

デメリット:

- サブリポジトリの扱いが曖昧になる
- Git履歴をきれいに保ちたい場合は不向き

### 案B: 既存のサブリポジトリは残し、新構成へは今後だけ寄せる

既存の `abc/`, `awc/`, `practice/` は残し、新しいものだけ `contests/` に置きます。

メリット:

- 壊れにくい
- Git の境界をいじらない
- 既存スクリプトへの影響が少ない

デメリット:

- しばらく旧構成と新構成が併存する

### 案C: Git履歴を保って移行する

各サブリポジトリをどう扱うか決めてから移します。

選択肢:

- ルートを1つの Git リポジトリに統合する
- `contests/atcoder/abc` などをサブモジュール風に扱う
- 履歴を残したいものだけ別リポジトリとして維持する

メリット:

- 長期的には一番きれい

デメリット:

- 手間が大きい
- Git の操作ミスが怖い

おすすめは **案B** です。まず新規作成分だけ新構成へ寄せ、既存分は必要になったタイミングで移します。

## Phase 7: practice を再配置する

現在:

```txt
practice/acl-beginner-contest/
practice/aoj/
practice/dp-contest/
practice/mizuiro/
practice/others/
practice/tenkei90/
```

移行後:

```txt
practice/atcoder/acl-beginner-contest/
practice/atcoder/dp-contest/
practice/atcoder/tenkei90/
practice/atcoder/others/
practice/aoj/
```

新しく ABC/ARC の過去問を練習する場合:

```txt
practice/atcoder/abc/abc350/c.cpp
practice/atcoder/arc/arc180/a.cpp
```

既存の `practice` も `.git` を持つため、ここも一気に移すより、新規分から適用するのが安全です。

## Phase 8: archive へ退避する

普段使わないものを archive へ移します。以下は実施済みです。

候補:

```txt
atcoder-novisteps-sync-main/
.claude/
abc/.claude/
awc/.claude/
practice/.claude/
abc/CLAUDE.md
abc/AGENTS.md
```

移行後:

```txt
archive/atcoder-novisteps-sync/
archive/old-settings/
```

判断:

- もう使わない: `archive/`
- 使う可能性があるツール: `tools/`
- 外部依存として必要: `vendor/`

## 推奨する最初の実作業

最初にやるなら、このくらいが安全です。

```txt
docs/structure-plan.md を作る
tools/ を作る
vendor/ を作る
archive/ を作る
contests/ を作る
.gitignore を整える
```

まだ既存の `abc/`, `awc/`, `practice/` は移しません。

実施済み:

```txt
atcoder-novisteps-sync-main/ -> archive/atcoder-novisteps-sync/
ac-library-master/ -> vendor/ac-library/
abc/setup -> tools/setup_abc のラッパー化
awc/setup_contest.sh -> tools/setup_awc のラッパー化
```

次にやるなら、既存の `abc`, `awc`, `practice` などをどこまで `contests/` と新しい `practice/` に寄せるかを決めます。

この順なら、見た目がかなり整理されつつ、壊れた時にも戻しやすいです。

## 完了条件

最終的に、ルート直下はこのくらいまで減らすのが目標です。

```txt
README.md
docs/
template/
library/
verify/
contests/
practice/
tools/
vendor/
archive/
.vscode/
.clang-format
.gitignore
```

この状態になれば、普段見るべきものと、たまにしか触らないものがきれいに分かれます。

## 注意点

- 既存フォルダに `.git` があるので、移動前に Git 方針を決める
- setup スクリプトの生成先を変える時は、実際にダミーコンテストで確認する
- ACL の場所を変える時は、include パスをすべて更新する
- 古い `.vscode` を消す前に、今使っているビルド方法を確認する
- `.DS_Store` や `build/` は削除してよいことが多いが、Git 管理されていないか確認する
