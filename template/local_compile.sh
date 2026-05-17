#!/usr/bin/env bash
set -euo pipefail

src="${1:-template/main.cpp}"
out="${2:-/tmp/a.out}"

g++ -std=c++20 -O2 -Wall -Wextra -Wshadow -DLOCAL \
    -I/Users/sagarayuto/kyopro \
    -I/Users/sagarayuto/kyopro/vendor/ac-library \
    "$src" -o "$out"

"$out"
