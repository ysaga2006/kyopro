# kyopro

競技プログラミング用の作業フォルダです。

このリポジトリには、本番コンテストのコード、精進用コード、C++テンプレート、自作ライブラリ、VS Code設定、運用メモをまとめています。

## 入口

- [運用ガイド](docs/operation.md): Git、コンテスト時、精進時、コミット方針
- [フォルダ構成ルール](docs/structure.md): `contests/` と `practice/` の使い分け、命名規則
- [構成移行計画](docs/structure-plan.md): 現在の整理方針と今後の移行メモ
- [ライブラリ説明](docs/library.md): `library/` と `template/` の詳しい説明
- [競プロメモ](docs/tips.md): 自分用の注意点・気づき

## よく使う操作

Git 操作は必ずリポジトリルートで行います。

```sh
cd /Users/sagarayuto/kyopro
git status --short
```

ABC / ARC のセットアップ:

```sh
./tools/setup_abc abc430
./tools/setup_abc arc180
```

AWC のセットアップ:

```sh
./tools/setup_awc 40
```

ライブラリの簡易確認:

```sh
./template/local_compile.sh verify/smoke.cpp
```

## 現在の主な構成

```txt
kyopro/
  contests/              # 今後の本番コンテスト置き場
  practice/              # 精進・復習コード
  abc/                   # 旧ABC/ARCコード置き場
  awc/                   # 旧AWCコード置き場
  ahc/                   # 旧AHCコード置き場
  codeforces/            # 旧Codeforcesコード置き場
  template/              # 提出テンプレート
  library/               # 自作C++ライブラリ
  tools/                 # setupスクリプトなど
  verify/                # ライブラリ確認用コード
  vendor/                # ACLなどの外部依存
  docs/                  # 運用・構成・ライブラリ説明
  archive/               # Git管理外の退避場所
```

新しく作る本番コンテストは `contests/` へ、精進・復習は `practice/` へ置きます。既存の `abc/`, `awc/`, `ahc/`, `codeforces/` は旧配置として残しています。

## Git管理

`kyopro` 全体を1つのGitリポジトリとして管理します。

Gitに入れるもの:

- 解答コード
- テンプレート
- ライブラリ
- docs
- tools
- VS Code設定
- ACLの実戦用ヘッダ

Gitに入れないもの:

- `input.txt`
- `output.txt`
- `build/`
- 実行ファイル
- `.DS_Store`
- `archive/`

詳しくは [docs/operation.md](docs/operation.md) を参照してください。

## デバッグ

VS CodeでF5実行すると、開いている `.cpp` と同じフォルダの `input.txt` を標準入力として使います。

`input.txt` がなければ、ビルド前に空ファイルが自動作成されます。

ローカルでは `-DLOCAL` が付くため、`debug(...)` が有効です。

