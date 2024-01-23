#!/bin/bash

set -euo pipefail

shopt -s globstar nullglob

UNIT_DIR="${1:-src/units}"
UNIT_SUFFIX="${2:-.unit.c}"
UNIT_MACRO="${3:-UNIT}"
UNIT_SYM_PREFIX="${4:-unit_}"

cd "$UNIT_DIR"

for unit_file in **/*"$UNIT_SUFFIX"
do
	unit_path="${unit_file:0:-${#UNIT_SUFFIX}}"
	echo "$UNIT_MACRO($UNIT_SYM_PREFIX${unit_path////_})"
done
