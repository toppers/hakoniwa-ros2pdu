import os
import re
from pathlib import Path

def find_ros_message_file(search_paths, package_name, message_name):
    for search_path in search_paths:
        path = Path(search_path) / package_name / 'msg' / f'{message_name}.msg'
        if path.exists():
            return path
    return None

def parse_ros_message_file(file_path):
    fields = []
    with open(file_path, 'r', encoding='utf-8') as f:
        for line in f:
            line = line.strip()
            if not line or line.startswith('#'):
                continue
            
            if '#' in line:
                line = line.split('#', 1)[0].strip()

            # '=' が含まれる行は PDU のフィールドとしては扱わない
            if '=' in line:
                continue # この行はスキップ

            parts = line.split()
            if len(parts) >= 2:
                field_type = parts[0]
                field_name = parts[1]
                
                fields.append({'type': field_type, 'name': field_name})
    return fields

def get_ros_message_definition(search_paths, package_msg):
    base_pkg_msg = package_msg.split('[', 1)[0].strip()
    try:
        package_name, message_name = base_pkg_msg.split('/')
    except ValueError:
        return None
    msg_file_path = find_ros_message_file(search_paths, package_name, message_name)
    if not msg_file_path:
        print(f"Warning: Could not find message definition for {package_msg}. Skipping.")
        return None
    fields = parse_ros_message_file(msg_file_path)
    return {
        'package': package_name,
        'message': message_name,
        'fields': fields
    }
