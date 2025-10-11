#!/usr/bin/env python3

from sys import argv
from elftools.elf.elffile import ELFFile

xml = open(argv[1], 'r').read()
elf_file = ELFFile(open(argv[2], 'rb'))
text_section = elf_file.get_section_by_name('.text')
output = open(argv[3], 'w')
xml = xml.replace('    ', '').replace('\r', '').replace('\n', '')
# Find and remove comments
while True:
    s = xml.find('<!--')
    if s == -1:
        break
    e = s+4 + xml[s+4:].find('-->')
    if e == -1:
        break
    xml = xml[:s] + xml[e+3:]
output.write(xml.replace("${INSERT_LOADER_DATA}", text_section.data().hex().upper()))
output.close()
