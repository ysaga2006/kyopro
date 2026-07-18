# kyopro

競技プログラミング用の作業フォルダです。

このリポジトリには、コンテスト問題のコード、教材・問題集の練習コード、C++テンプレート、自作ライブラリ、VS Code設定、運用メモをまとめています。

## 入口

- [運用ガイド](docs/operation.md): Git、コンテスト時、精進時、コミット方針
- [フォルダ構成ルール](docs/structure.md): `contests/` と `practice/` の使い分け、命名規則
- [構成移行計画](docs/structure-plan.md): 旧構成から移行した記録
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
./sabc abc430
./sabc arc180
```

AWC のセットアップ:

```sh
./sawc 40
```

ライブラリの簡易確認:

```sh
./template/local_compile.sh verify/smoke.cpp
```

## 現在の主な構成

```txt
kyopro/
  contests/              # 通常のコンテスト問題（参加時期を問わない）
  practice/              # 教材・問題集・テーマ練習
  template/              # 提出テンプレート
  library/               # 自作C++ライブラリ
  tools/                 # setupスクリプトなど
  verify/                # ライブラリ確認用コード
  vendor/                # ACLなどの外部依存
  docs/                  # 運用・構成・ライブラリ説明
  archive/               # Git管理外の退避場所
```

ABCなどの通常のコンテスト問題は、リアルタイム参加でも過去問演習でも `contests/` へ置きます。`practice/` は典型90、ADT、DP Contest、AOJなど、教材・問題集単位で取り組むコードに使います。

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
