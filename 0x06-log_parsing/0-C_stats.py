#!/usr/bin/python3
""" Module for Log Parsing Script """
import re
import sys


class LogParsing:
    """ Parses a Log and computes metrics"""
    def __init__(self):
        self.log = {}
        self.file_size = 0
        self.n_lines = 0

    def read_stdin(self):
        """
        Method that reads stdin line by line and parses
        response code and file size
        """
        try:
            for line in sys.stdin:
                try:
                    RESPONSE = re.findall(r'\s\d{3}', line)
                    CODE = RESPONSE[0].strip()
                    SIZE = RESPONSE[1].strip()
                    if CODE:
                        self.log[CODE] = self.log.get(CODE, 0) + 1
                        self.file_size += int(SIZE)
                except Exception:
                    pass

                self.n_lines += 1
                if self.n_lines == 10:
                    self.print_log()
        except KeyboardInterrupt:
            self.print_log()
            raise
        else:
            self.print_log()

    def print_log(self):
        """ Method that prints metrics """
        self.n_lines = 0
        print("File size:", self.file_size)
        for code in sorted(self.log.keys()):
            print(f"{code}: {self.log[code]}")


if __name__ == '__main__':
    s = LogParsing()
    s.read_stdin()
