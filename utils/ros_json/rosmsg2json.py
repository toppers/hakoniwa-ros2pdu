#!/usr/bin/python
# -*- coding: utf-8 -*-
import json
import os
import sys

# コマンドライン引数のチェック
if len(sys.argv) != 3:
    print('Usage: ' + sys.argv[0] + ' <ROS Message file> <Destination directory>')
    sys.exit(1)  # エラーコードを1にして終了

# ファイル名とディレクトリの取得
in_file_path = sys.argv[1]
in_file = os.path.basename(in_file_path)
out_file = in_file.replace('.msg', '.json')
out_dir = sys.argv[2]
in_dir = os.path.dirname(in_file_path)

# 出力データの構造を初期化
out_data = {'fields': []}

# ファイルの読み込みとデータの解析
with open(os.path.join(in_dir, in_file), 'r') as file:
    for line in file:
        stripped_line = line.strip()
        # コメント行または空行、または'='を含む行をスキップ
        if stripped_line and not stripped_line.startswith('#') and '=' not in stripped_line:
            parts = stripped_line.split()
            # フィールド名と型を辞書に追加
            if len(parts) >= 2:  # 配列に少なくとも2つの要素が必要
                entry = {'name': parts[1], 'type': parts[0]}
                out_data['fields'].append(entry)

# JSONファイルとしてデータを書き出し
out_path = os.path.join(out_dir, out_file)
with open(out_path, 'w', encoding='utf-8') as file:
    json.dump(out_data, file, ensure_ascii=False, indent=2)
