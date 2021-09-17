#!/usr/bin/python3
""" Lockboxes solution """


def canUnlockAll(boxes):
    """ determine if all the boxes can be opened """

    num_boxes = len(boxes)
    keys = [0]
    seen = set()

    while keys:
        k = keys.pop()
        if (k < num_boxes and k >= 0):
            seen.add(k)

            for key in boxes[k]:
                if key not in seen:
                    keys.append(key)

    return len(seen) == num_boxes
