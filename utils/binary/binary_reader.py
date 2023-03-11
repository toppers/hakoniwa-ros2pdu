#!/usr/bin/python
# -*- coding: utf-8 -*-
import json
import sys

import binary_io
import offset_parser
import base64

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
                json_data[name] = value
            else:
                encode_type = "text"
                array_size = offset_parser.array_size(line)
                one_elm_size = int(size / array_size)
                if (array_size > 100):
                    encode_type = "base64"
                    bin = binary_io.readBinary(binary_filepath, off, size)
                    array_value = base64.b64encode(bin).decode('utf-8')
                else:
                    i = 0
                    array_value = []
                    while i < array_size:
                        bin = binary_io.readBinary(binary_filepath, off + (i * one_elm_size), one_elm_size)
                        value = binary_io.binTovalue(type, bin)
                        array_value.append(value)
                        i = i + 1
                json_data[name + '_encode_type'] = encode_type
                json_data[name] = array_value
        else:
            if (offset_parser.is_single(line)):
                tmp_json_data = {}
                binary_read_recursive(tmp_json_data, off, type)
                json_data[name] = tmp_json_data
            else:
                i = 0
                array_size = offset_parser.array_size(line)
                one_elm_size = int(size / array_size)
                array_value = []
                while i < array_size:
                    tmp_json_data = {}
                    binary_read_recursive(tmp_json_data, off + (i * one_elm_size), type)
                    array_value.append(tmp_json_data)
                    i = i + 1
                json_data[name] = array_value

json_data = {}
binary_read_recursive(json_data, 0, typename)

print(json.dumps(json_data))
