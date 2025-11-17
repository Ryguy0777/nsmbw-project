#!/usr/bin/env python3

from sys import argv
from elftools.elf.elffile import ELFFile
import re

xml = open(argv[1], 'r').read()
elf_file = ELFFile(open(argv[2], 'rb'))
text_section = elf_file.get_section_by_name('.text')
output = open(argv[3], 'w')

# Remove indentation and newlines
xml = xml.replace('    ', '').replace('\r', '').replace('\n', '')

# Find and remove comments
xml = re.sub(r'<!--.*?-->', '', xml)

# Replace patch IDs with shortened versions
matches = re.findall(r'\sid="(.*?)"', xml)
unique_matches = set(matches)
m = 0
for match in unique_matches:
    if m < 10:
        short_id = f'{m}'
    else:
        short_id = chr(ord('a') + m - 10)
    xml = xml.replace(f'id="{match}"', f'id="{short_id}"')
    m += 1

xml = xml.replace("${INSERT_LOADER_DATA}", text_section.data().hex().upper())
output.write(xml)
output.close()
