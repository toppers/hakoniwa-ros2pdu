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
	print("ERROR: generate_proxy.py <tpl_file> <custom_json>")
	sys.exit()

tpl_file=sys.argv[1] 
custom_json_file=sys.argv[2]

class RosMessageContainer:
    pass

global container
container = RosMessageContainer()

def get_pkg(item):
	return item["type"].split('/')[0]

def get_type(item):
	return item["type"].split('/')[1]

def get_channel(item):
	return item["channel_id"]

def get_pdu_size(item):
	return item["pdu_size"]

def get_topic_name(item):
	return item["name"].replace('/', '_')

tmp_file = open(custom_json_file)
container.get_pkg = get_pkg
container.get_type = get_type
container.get_pdu_size = get_pdu_size
container.get_channel = get_channel
container.get_topic_name = get_topic_name
container.json_data = json.load(tmp_file)

tpl = env.get_template(tpl_file)
out = tpl.render({'container':container})

print(out)

