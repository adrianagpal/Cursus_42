#!/usr/bin/env python3
 
import numpy as np

#class MazeGenerator():
#    def __init__(self, size, seed):


def read_format(config_file):
    width = 0
    height = 0
    with open(config_file) as config_file:
        config = config_file.readlines()
    for line in config:
        print(line)
        if line.startswith("WIDTH="):
            width = int(line.split('=')[1])
        elif line.startswith("HEIGHT="):
            height = int(line.split('=')[1])

    arr = np.zeros((height, width))
    return arr


def swap_nibbles(x):
    bit_swap = x << 2
    print(bit_swap)
    first = (bit_swap >> 4) & 0xF
    print(first)
    result = bit_swap | first
    print(result)
    """Get 4 low order bits from a byte."""
    final = result & 0x0F
    return (final)

#def convert_to_byte():

arr = read_format("config.txt")
print(arr)

x = 14
new_nibble = swap_nibbles(x)
print(new_nibble)

print(new_nibble >> 0 & 1)
print(new_nibble >> 1 & 1)
print(new_nibble >> 2 & 1)
print(new_nibble >> 3 & 1)

# Put random hex numbers taking into account the restrictions of the corresponding bit.
