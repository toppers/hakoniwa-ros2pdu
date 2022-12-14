#!/usr/bin/python
# -*- coding: utf-8 -*-
import json
import sys

import binary_io
import offset_parser

if len(sys.argv) != 4:
	print("Usage: binary_reader.py <offset_path> <typename> <binary_file> ")
	sys.exit()

offset_path=sys.argv[1] 
typename=sys.argv[2]
binary_filepath=sys.argv[3]

def binary_read_recursive(json_data, base_off, typename):
    filepath = binary_io.find_filepath(offset_path +"/*/", typename + ".offset")
    lines = offset_parser.parse_offset(filepath)
    for line in lines:
        off = offset_parser.member_off(line) + base_off
        type = offset_parser.member_type(line)
        name = offset_parser.member_name(line)
        size = offset_parser.member_size(line)
        if (offset_parser.is_primitive(line)):
            if (offset_parser.is_single(line)):
                bin = binary_io.readBinary(binary_filepath, off, size)
                value = binary_io.binTovalue(type, bin)
                json_data.append(
                    {
                        "name": name,
                        "type": type,
                        "value": value
                    }
                )
            else:
                i = 0
                array_size = offset_parser.array_size(line)
                one_elm_size = int(size / array_size)
                array_value = []
                while i < array_size:
                    bin = binary_io.readBinary(binary_filepath, off + (i * one_elm_size), one_elm_size)
                    value = binary_io.binTovalue(type, bin)
                    array_value.append(value)
                    i = i + 1
                json_data.append(
                    {
                        "name": name,
                        "type": type,
                        "value": array_value
                    }
                )
        else:
            if (offset_parser.is_single(line)):
                tmp_json_data = {
                    "fields": []
                }
                binary_read_recursive(tmp_json_data['fields'], off, type)
                json_data.append(
                    {
                        "name": name,
                        "type": type,
                        "value": tmp_json_data
                    }
                )
            else:
                i = 0
                array_size = offset_parser.array_size(line)
                one_elm_size = int(size / array_size)
                array_value = []
                while i < array_size:
                    tmp_json_data = {
                        "fields": []
                    }
                    binary_read_recursive(tmp_json_data['fields'], off + (i * one_elm_size), type)
                    array_value.append(tmp_json_data)
                    i = i + 1
                json_data.append(
                    {
                        "name": name,
                        "type": type,
                        "value": array_value
                    }
                )

json_data = {
    "fields": []
}
binary_read_recursive(json_data['fields'], 0, typename)

print(json.dumps(json_data))
