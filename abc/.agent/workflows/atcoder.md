---
description: AtCoderの問題を解くためのワークフロー（テスト・提出・デバッグ）
---

# AtCoder ワークフローメモ

---

## A. リアルタイムコンテスト参加時

### 1. セットアップ（コンテスト開始前）

```bash
cd /Users/sagarayuto/kyopro/abc
./setup_contest.sh abc999           # a〜gの7問分を作成
./setup_contest.sh abc999 d e       # 途中から問題を追加する場合
```

フォルダ構造：

```
abc9xx/abc999/
  a/
    main.cpp   ← コードを書く
    input.txt  ← デバッグ用サンプル入力をここに貼る
    build/     ← コンパイル済みバイナリ（gitignore）
    test/      ← oj でサンプルを取得した場合
```

### 2. コーディング

```bash
code abc4xx/abc999/a/main.cpp
```

### 3. テストケースの準備

**方法A: oj で自動取得（コンテストからしばらくしてから？）**

```bash
cd abc4xx/abc999/a
oj d https://atcoder.jp/contests/abc999/tasks/abc999_a
```

`test/sample-1.in` / `test/sample-1.out` などが生成されます。

**方法B: 手動で作成**

```bash
cd abc4xx/abc999/a
mkdir -p test

cat > test/sample-1.in << 'EOF'
3
1 2 3
EOF

cat > test/sample-1.out << 'EOF'
6
EOF
```

### 4. ビルド & テスト

VSCode のショートカット：
- `Cmd+Shift+B` → ビルド（`Build` タスク）
- `Cmd+Shift+P` → `Tasks: Run Task` → `Test` でテスト

CLI でやる場合：

```bash
cd abc4xx/abc999/a

# ビルド
g++ -g -std=c++23 -Wall -Wextra -D_GLIBCXX_DEBUG \
  -I/opt/homebrew/Cellar/gcc/15.1.0/include/c++/15/ac-library-master \
  main.cpp -o build/main

# テスト（全サンプルケース）
oj t -c ./build/main -d test
```

### 5. 提出

```bash
cat main.cpp | pbcopy
```

ブラウザで問題ページの「提出」を開き、`Cmd+V` で貼り付け → 言語を `C++23 (GCC 15)` に → 提出。

>  `acc s` は現在セキュリティ強化により使用できない？

### 6. 次の問題へ

```bash
cd ../b
# → 手順 2 から繰り返し
```

---

## B. 過去問精進時

### 1. セットアップ（テストケース自動取得）

```bash
cd /Users/sagarayuto/kyopro/ABC
acc new abc999
```

`abc4xx/abc999/a/main.cpp` と `abc4xx/abc999/a/test/` が自動生成される。

### 2. 以降はコンテスト時と同じ

手順 2〜5 を繰り返す。

---

## C. よく使うコマンドたち

```bash
# === セットアップ ===
acc new abc999                               # 過去問: フォルダ + テストケース取得
./setup_contest.sh abc999                    # ライブ: a〜g を全作成
./setup_contest.sh abc999 d e               # ライブ: d, e だけ追加
oj d https://atcoder.jp/contests/abc999/tasks/abc999_a  # テストケース追加取得

# === ビルド & テスト ===
g++ -g -std=c++23 -Wall -Wextra -D_GLIBCXX_DEBUG \
  -I/opt/homebrew/Cellar/gcc/15.1.0/include/c++/15/ac-library-master \
  main.cpp -o build/main
oj t -c ./build/main -d test                # サンプルケースでテスト

# === 提出 ===
cat main.cpp | pbcopy                        # コードをクリップボードにコピー

# === Git コミット ===
gac "AC: ABC300 A"                           # 全変更を保存＋コミット
# コミットメッセージ例: "AC: ...", "WA/TLE: ...", "WIP/save: ..."

# === デバッグ（CLI） ===
./build/main < input.txt                     # input.txt を入力として実行
./build/main                                 # 手動入力で実行（Ctrl+D で入力終了）

# === ログイン確認 ===
oj login --check https://atcoder.jp/
```

---

## D. デバッグ

### VS Code デバッガ

**使い方：**

1. `input.txt` にサンプル入力を貼る（`main.cpp` と同じフォルダ）
2. `main.cpp` を開いた状態でブレークポイントを設定（行番号の左をクリック）
3. `F5` でデバッグ開始
4. 「デバッグ コンソール」タブに出力が表示される

**ポイント：**
- ブレークポイントは**その行を実行する直前**で止まる
  - 例: `cin >> n;` の行で止まった場合、まだ `n` は読まれていない
  - `F10`（ステップオーバー）で1行進めると `n` に値が入る
  - または次の行にブレークポイントを置く
- 変数の値は左の「変数」パネルに自動表示される

**操作キー：**

| キー | 操作 |
|------|------|
| `F5` | 開始 / 次のブレークポイントまで続行 |
| `F10` | ステップオーバー（1行進む） |
| `F11` | ステップイン（関数の中に入る） |
| `Shift+F11` | ステップアウト |
| `Shift+F5` | 停止 |

**仕組み：**
- デバッガ: CodeLLDB（VSCode拡張）
- stdin: `${fileDirname}/input.txt` から自動読み込み
- stdout: 「デバッグ コンソール」タブに出力

### CLI でのデバッグ（lldb）

```bash
lldb ./build/main

(lldb) breakpoint set --file main.cpp --line 15   # ブレークポイント設定
(lldb) b main.cpp:15                               # 短縮形
(lldb) run < input.txt                             # input.txt を入力として実行
(lldb) n                                           # ステップオーバー
(lldb) s                                           # ステップイン
(lldb) c                                           # 次のブレークポイントまで続行
(lldb) p i                                         # 変数 i の値を表示
(lldb) p v                                         # ベクター v の内容を表示
(lldb) bt                                          # スタックトレース（エラー行の特定）
(lldb) q                                           # 終了
```

### vectorの範囲外アクセス

`-D_GLIBCXX_DEBUG` が有効なので、`v[i]` でも範囲外アクセスは検出されます。

```bash
# F5 でデバッグ実行 → クラッシュ行で自動停止
# または CLI:
lldb ./build/main
(lldb) run < input.txt
# クラッシュしたら:
(lldb) bt    # スタックトレースに行番号が表示される
```

---

## E. 環境情報

| 項目 | 設定 |
|------|------|
| コンパイラ | GCC 15 (`/usr/local/bin/g++`) |
| C++バージョン | C++20 |
| デバッグフラグ | `-D_GLIBCXX_DEBUG` |
| デバッガ | CodeLLDB（VSCode拡張） |
| テストツール | `oj` (online-judge-tools) |
| コンテストツール | `acc` (atcoder-cli) |
| テンプレート | `~/Library/Preferences/atcoder-cli-nodejs/cpp/main.cpp` |

---

## F. トラブルシューティング

```bash
# oj のログイン状態確認
oj login --check https://atcoder.jp/

# テストケースがないときに取得
oj d https://atcoder.jp/contests/abc999/tasks/abc999_a

# build/ フォルダがないと言われたら
mkdir -p build

# フォーマッタを手動で適用（VS Code上で）
# Shift + Option + F
```
