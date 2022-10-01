#!/usr/bin/python
# -*- coding: utf-8 -*-
import json
import sys
import glob
import re
import string
from jinja2 import Template, Environment, FileSystemLoader

env = Environment(loader=FileSystemLoader('./', encoding='utf8'))

if len(sys.argv) != 3:
	print("ERROR: generate.py <tpl_file> <ros_topics>")
	sys.exit()

tpl_file=sys.argv[1] 
ros_topics_file=sys.argv[2]

class RosMessageContainer:
    pass

global container
container = RosMessageContainer()

def get_pkg(item):
	return item["topic_type_name"].split('/')[0]

def get_type(item):
	return item["topic_type_name"].split('/')[1]

def is_pub(item):
	return (item["sub"] == True)

def is_sub(item):
	return (item["sub"] == False)

def get_index(item):
	global container
	return container.json_data["fields"].index(item)

tmp_file = open(ros_topics_file)
container.get_pkg = get_pkg
container.get_type = get_type
container.is_pub = is_pub
container.is_sub = is_sub
container.get_index = get_index
container.json_data = json.load(tmp_file)

tpl = env.get_template(tpl_file)
out = tpl.render({'container':container})

print(out)

