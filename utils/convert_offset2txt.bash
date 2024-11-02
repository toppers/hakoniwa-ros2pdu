#!/bin/bash

if [ $# -ne 1 ]
then
    echo "Usage: $0 <target_dir>"
    exit 1
fi

TARGET_DIR="$1"

# .offsetファイルを再帰的に検索し、.txtにリネーム
find "$TARGET_DIR" -type f -name "*.offset" | while read file; do
  new_file="${file%.offset}.txt"
  mv "$file" "$new_file"
  echo "Renamed: $file -> $new_file"
done

echo "All .offset files have been renamed to .txt"
