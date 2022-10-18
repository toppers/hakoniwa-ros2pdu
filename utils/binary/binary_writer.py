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
json_data = json.load(json_open)
    
filepath = binary_io.find_filepath(offset_path +"/*/", typename + ".offset")
lines = offset_parser.parse_offset(filepath)

for v in json_data['fields']:
    line = offset_parser.select_by_name(lines, v['name'])
    off = offset_parser.member_off(line)
    type = offset_parser.member_type(line)
    bin = binary_io.typeTobin(type, v['value'])
    binary_io.writeBinary(outfile, off, bin)

