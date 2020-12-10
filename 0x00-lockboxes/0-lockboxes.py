#!/usr/bin/python3
"""Module for 0-lockboxes"""


def canUnlockAll(boxes):
    """Method that solves Lockboxes problem"""
    if type(boxes) is not list or len(boxes) == 0:
        return False
    unlocked = [False] * len(boxes)
    unlocked[0] = True
    keys = [0]
    while keys:
        index = keys.pop()
        for key in boxes[index]:
            if not unlocked[key] and key < len(boxes):
                unlocked[key] = True
                keys.append(key)
    return all(unlocked)
