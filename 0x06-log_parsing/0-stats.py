#!/usr/bin/python3
""" Module for Log Parsing Script """
import re
import sys


if __name__ == '__main__':
    n_lines = 0
    file_size = 0
    log = {}

    def print_log():
        """ Method that prints metrics """
        print("File size:", file_size)
        for code in sorted(log.keys()):
            print(f"{code}: {log[code]}")
    try:
        for line in sys.stdin:
            n_lines += 1
            RESPONSE = re.findall(r'\s\d{3}', line)
            CODE = RESPONSE[0].strip()
            SIZE = 0 if len(RESPONSE) < 2 else RESPONSE[1].strip()
            if CODE:
                log[CODE] = log.get(CODE, 0) + 1
                file_size += int(SIZE)

            if n_lines == 10:
                n_lines = 0
                print_log()
    except KeyboardInterrupt:
        print_log()
        raise
    else:
        print_log()
