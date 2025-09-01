#!/usr/bin/env python3

from sys import argv

xml = open(argv[1], 'r').read()
loader = open(argv[2], 'rb').read().hex().upper()
output = open(argv[3], 'w')
output.write(xml.replace("${INSERT_LOADER_DATA}", loader))
output.close()