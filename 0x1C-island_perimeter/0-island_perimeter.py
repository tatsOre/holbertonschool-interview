#!/usr/bin/python3
"""Module for island_perimeter"""


def island_perimeter(grid):
    """Returns the perimeter of the island described in <grid>"""
    w = len(grid[0])
    h = len(grid)
    p = 0
    for r in range(h):
        for c in range(w):
            if grid[r][c] == 1:
                p += 1 if r == 0 or grid[r-1][c] == 0 else 0
                p += 1 if r == h - 1 or grid[r+1][c] == 0 else 0
                p += 1 if c == w - 1 or grid[r][c+1] == 0 else 0
                p += 1 if c == 0 or grid[r][c-1] == 0 else 0
    return p
