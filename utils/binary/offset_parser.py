#!/usr/bin/python
# -*- coding: utf-8 -*-


from select import select


def parse_offset(filepath):
    with open(filepath) as f:
        lines = f.readlines()
        return lines

def select_by_name(lines, name):
    for line in lines:
        if member_name(line) == name:
            return line
    return None

def member_name(data):
    return data.split(":")[2]

def member_type(data):
    return data.split(":")[3]

def is_primitive(data):
    return data.split(":")[1] == "primitive"

def is_single(data):
    return data.split(":")[0] == "single"

def array_size(data):
    if (is_single(data)):
        return 0
    return int(data.split(":")[5])

def member_off(data):
    return int(data.split(":")[4])
