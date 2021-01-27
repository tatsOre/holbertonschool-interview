#!/usr/bin/python3
""" Module for Log Parsing Script """
import sys


if __name__ == '__main__':
    log = {'200': 0, '301': 0, '400': 0, '401': 0,
           '403': 0, '404': 0, '405': 0, '500': 0}
    file_size = 0

    def print_log():
        """ Method that prints metrics """
        print("File size:", file_size)
        for code in sorted(log.keys()):
            if log[code]:
                print(f"{code}: {log[code]}")
    try:
        n_lines = 0
        for line in sys.stdin:
            try:
                response = line.split()
                code = response[-2]
                size = response[-1]
                if code in log:
                    log[code] += 1
                    file_size += int(size)
            except:
                pass

            n_lines += 1

            if n_lines == 10:
                n_lines = 0
                print_log()
    except KeyboardInterrupt:
        print_log()
        raise
    else:
        print_log()
