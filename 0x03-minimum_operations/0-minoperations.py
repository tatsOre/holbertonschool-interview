#!/usr/bin/python3
"""
Module for 0. Minimum Operations
"""


def minOperations(n):
    """Method that calculates the fewest number of operations needed
    to result in exactly n H characters in the file."""
    if n <= 1:
        return 0

    operations, divisor = 0, 2
    while n > 1:
        if (n % divisor) == 0:
            n = n // divisor
            operations += divisor
        else:
            divisor += 1
    return operations
