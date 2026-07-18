# kyopro フォルダ構成ルール

この文書は、`kyopro`の現在の配置ルールをまとめたものです。

## 一番大事なルール

コードの置き場所は、リアルタイム参加か後日の精進かではなく、**問題の出典とまとまり**で決めます。

- ABC・ARC・AHC・AWCなど、通常のコンテスト問題: `contests/`
- 典型90・ADT・DP Contest・AOJなど、教材や問題集として取り組むもの: `practice/`
- 繰り返し使う自作ライブラリ: `library/`
- 提出コードの土台: `template/`
- 外部ライブラリ: `vendor/`
- 普段使わない退避物: `archive/`

「いつ解いたか」はGit履歴で分かるため、保存場所では区別しません。

ABC350 Cを過去問として解く場合も、次に置きます。

```txt
contests/atcoder/abc/abc350/c/main.cpp
```

既に解答がある問題を解き直す場合は、通常は同じ`main.cpp`を更新します。以前の実装はGit履歴から確認できます。複数実装を同時に残す必要がある場合だけ、`main_alt.cpp`など目的の分かる名前を追加します。

## 全体構成

```txt
kyopro/
  contests/
    atcoder/
      abc/
      arc/
      ahc/
      awc/
    codeforces/
  practice/
    adt/
    aoj/
    atcoder/
      acl-beginner-contest/
      dp-contest/
      others/
    mizuiro/
    tenkei90/
  template/
  library/
  verify/
  tools/
  vendor/
  docs/
  archive/
```

`practice/`の既存シリーズは、無理に階層を揃えるためだけの移動はしません。シリーズ名から探せる現在の配置を維持します。

## contests のルール

AtCoder ABC・ARCは1問1フォルダで、ソース名を`main.cpp`に統一します。

```txt
contests/atcoder/abc/abc430/a/main.cpp
contests/atcoder/abc/abc430/b/main.cpp
contests/atcoder/arc/arc180/a/main.cpp
```

新規作成にはルートのコマンドを使います。

```sh
./sabc abc430
./sabc arc180
./sawc 40
```

AWCは`a`から`e`まで作成されます。Codeforcesは既存配置に合わせます。

```txt
contests/codeforces/1076/a.cpp
contests/codeforces/1076/b.cpp
```

## practice のルール

`practice/`は「精進したコード全部」ではなく、教材・問題集・テーマ練習のまとまりに使います。

```txt
practice/tenkei90/001.cpp
practice/tenkei90/042.cpp
practice/adt/20260602_2/a.cpp
practice/atcoder/dp-contest/a.cpp
practice/aoj/ITP1_3_D.cpp
```

命名規則:

- 問題記号がある教材: `a.cpp`, `b.cpp`
- 番号管理の教材: `001.cpp`, `042.cpp`のようにゼロ埋め
- AOJ: 公式の問題ID
- 同じシリーズでは既存の命名規則を優先
- メモや生成器が必要な場合だけ1問1フォルダにする

通常のABCやARCの過去問を`practice/atcoder/abc/`へ複製する運用はしません。`contests/`の出典に対応する場所を使います。

## ローカルファイルとテスト

入力、期待出力、ビルド成果物はGit管理しません。

1問1フォルダの`main.cpp`では、同じフォルダの`test/`を使います。

```txt
a/
  main.cpp
  input.txt
  test/
    01.in
    01.out
```

1フォルダに複数の`.cpp`がある教材では、ファイル名ごとにテストを分けます。

```txt
tenkei90/
  032.cpp
  076.cpp
  test/
    032/
      01.in
      01.out
    076/
      01.in
      01.out
```

`./stest`はソース名を見て、この配置を自動選択します。

## template / library / verify

- `template/main.cpp`: setupがコピーする提出用テンプレート
- `library/`: ACLにない、自分で繰り返し使う部品
- `verify/`: 自作ライブラリの動作確認

テンプレート更新時は、`.vscode/kyopro.code-snippets`の`main`スニペットも同時に更新します。ACLにある機能は原則として再実装しません。

## tools / vendor / archive

- `tools/`: setupやテスト実行などの補助スクリプト
- `vendor/ac-library/`: AtCoder Library
- `archive/`: 古いGit情報や設定の退避場所。Git管理外

設定は原則としてルートの`.clang-format`と`.vscode/`に集約します。

## 迷った時

- ABCなど特定コンテストの問題: `contests/`の対応する場所
- 教材・問題集を順に解く: `practice/`のシリーズ名
- 何度も使う部品: `library/`
- 提出の土台: `template/`
- ライブラリ確認: `verify/`
- 外部依存: `vendor/`
- 普段見ない退避物: `archive/`

保存場所に迷ったときは、「今は精進か」ではなく「その問題を後からどの名前で探すか」で決めます。
