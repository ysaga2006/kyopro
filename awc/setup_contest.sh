#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
KYOPRO_ROOT="$(cd "$SCRIPT_DIR/.." && pwd)"

exec "$KYOPRO_ROOT/tools/setup_awc" "$@"
