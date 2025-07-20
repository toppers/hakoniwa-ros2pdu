# utils/hakoniwa_pdu_generator/offset_parser.py

import struct
from pathlib import Path
from typing import List, Dict, Any

# オフセットファイルの各エントリに対応するクラス
class PduOffsetEntry:
    def __init__(self, array_type, data_type, member_name, type_name, offset, size, array_len):
        self.array_type: str = array_type
        self.data_type: str = data_type
        self.member_name: str = member_name
        self.type_name: str = type_name
        self.offset: int = offset
        self.size: int = size
        self.array_len: int = array_len

    def to_dict(self):
        return self.__dict__

    def __repr__(self):
        return f"PduOffsetEntry({self.to_dict()})"

def _parse_string(buffer: bytes, offset: int) -> (str, int):
    """NULL終端文字列をバッファから読み込む"""
    end = buffer.find(b'\0', offset)
    if end == -1:
        raise ValueError("String not null-terminated")
    return buffer[offset:end].decode('utf-8'), end + 1

def parse_offset_file(file_path: Path) -> List[PduOffsetEntry]:
    """
    指定されたテキスト形式のオフセットファイルをパースする。
    """
    if not file_path.exists():
        return []

    with open(file_path, 'r', encoding='utf-8') as f:
        lines = f.readlines()
    
    entries = []
    for line in lines:
        if not line.strip() or line.startswith('//'):
            continue
        parts = line.strip().split(':')
        if len(parts) < 6:
            continue

        array_type, data_type, member_name, type_name, offset, size = parts[:6]
        array_len_str = parts[6] if len(parts) > 6 else "1"

        entry = PduOffsetEntry(
            array_type.strip(),
            data_type.strip(),
            member_name.strip(),
            type_name.strip(),
            int(offset.strip()),
            int(size.strip()),
            int(array_len_str.strip())
        )
        entries.append(entry)

    return entries

