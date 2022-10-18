#!/usr/bin/python
# -*- coding: utf-8 -*-
import json
import sys

import binary_io
import offset_parser

if len(sys.argv) != 5:
	print("Usage: binary_writer.py <offset_path> <typename> <binary_def_json> <outfile>")
	sys.exit()

offset_path=sys.argv[1] 
typename=sys.argv[2]
binary_def_json=sys.argv[3]
outfile=sys.argv[4]

json_open = open(binary_def_json, 'r')
base_json_data = json.load(json_open)

def binary_write_recursive(json_data, base_off, typename):
    filepath = binary_io.find_filepath(offset_path +"/*/", typename + ".offset")
    lines = offset_parser.parse_offset(filepath)
    for v in json_data['fields']:
        line = offset_parser.select_by_name(lines, v['name'])
        off = offset_parser.member_off(line) + base_off
        type = offset_parser.member_type(line)
        if (offset_parser.is_primitive(line)):
            if (offset_parser.is_single(line)):
                bin = binary_io.typeTobin(type, v['value'])
                binary_io.writeBinary(outfile, off, bin)
            else:
                i = 0
                elm_size = offset_parser.member_size(line)
                array_size = offset_parser.array_size(line)
                one_elm_size = int(elm_size / array_size)
                for elm in v['value']:
                    bin = binary_io.typeTobin(type, elm)
                    binary_io.writeBinary(outfile, off + (i * one_elm_size), bin)
                    i = i + 1
        else:
            if (offset_parser.is_single(line)):
                binary_write_recursive(v['value'], off, type)
            else:
                i = 0
                elm_size = offset_parser.member_size(line)
                array_size = offset_parser.array_size(line)
                one_elm_size = int(elm_size / array_size)
                for elm in v['value']:
                    binary_write_recursive(elm, off + (i * one_elm_size), type)
                    i = i + 1
            

binary_write_recursive(base_json_data, 0, typename)