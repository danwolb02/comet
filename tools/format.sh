#!/bin/bash

SOURCE_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

cd $SOURCE_DIR
./format.py -r .. > formatted.diff

cd ..
git apply $SOURCE_DIR/formatted.diff
