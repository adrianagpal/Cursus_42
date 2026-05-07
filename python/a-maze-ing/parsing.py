#!/usr/bin/env python3
 
import numpy as np
import random
from typing import Any

#class MazeGenerator():
#    def __init__(self, size, seed):


allowed_keys = ['WIDTH', 'HEIGHT', 'ENTRY', 'EXIT', 'OUTPUT_FILE', 'PERFECT', 'SEED', 'ALGORITHM']
algo_list = []


def open_file(config_file) -> list[str]:

    with open(config_file) as config_file:
        config: list[str] = config_file.readlines()

    return config

"""
Checks if all required keys are provided in the config file
and there are no duplicates, or extra keys
"""
def check_keys(config) -> bool:

    keys: list[str] = []

    for line in config:
        line.strip()
        if not line.startswith('#'):
            key: str = line.split('=')[0].strip()
            keys.append(key.upper())
    
    return sorted(allowed_keys) == sorted(keys)


def get_keys_dict(config) -> dict[str, Any]:
    keys_dict = {}

    if check_keys(config):    
        for item in config:
            try:
                key, value = item.strip().split('=', 1)
                key = key.upper()
                keys_dict[key] = value

            except Exception as e:
                print(e)

    return keys_dict

"""
Check valid coordinates without spaces
"""
def is_coordinate(s: str) -> bool:
    parts = s.split(',')

    if len(parts) != 2:
        return None
    
    if parts[0].isdigit() and parts[1].isdigit():
        return int(parts[0]), int(parts[1]) 
    
    return None

def check_data_format(keys_dict):

    for item in keys_dict:
        if item in ('WIDTH', 'HEIGHT', 'SEED'):
            keys_dict[item] = int(keys_dict[item])
        elif item == 'PERFECT':
            print(keys_dict[item].upper())
            if keys_dict[item].upper() == 'TRUE':
                keys_dict[item] = True
            elif keys_dict[item].upper() == 'FALSE':
                keys_dict[item] = False
            else:
                raise Exception("algo pasa")
        elif item in ('ENTRY', 'EXIT'):
            coord = is_coordinate(keys_dict[item])
            if coord:
                keys_dict[item] = coord
            else:
                raise Exception("algo si pasa")
    print("Dictionary succesfully registered")  
    return(keys_dict)

def check_entry_exit(keys_dict):
    entry = keys_dict['ENTRY']
    exit_coord = keys_dict['EXIT']
    width = keys_dict['WIDTH']
    height = keys_dict['HEIGHT']

    if entry == exit:
        return False

    if (
        entry[0] > width or
        exit_coord[0] > width or
        entry[1] > height or
        exit_coord[1] > height
    ):
        return False

    return True



    #np.random.seed(seed)

    # Creates a matrix of random numbers from 1 to 15
    #mat = np.random.randint(1, 16, size=(height, width))
    # Formats matrix into hexadecimal format
    #hex_mat = np.vectorize(lambda x: format(x, 'X'))(mat)
    #return mat


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


def main() -> None:
    config = open_file("config.txt")
    
    keys_dict = get_keys_dict(config)

    if not bool(keys_dict):
        print("Invalid format")
        exit()
    try:
        keys_dict = check_data_format(keys_dict)
        print(keys_dict)
    except Exception as e:
        print(e)

    if check_entry_exit(keys_dict):
        


#def convert_to_byte():

def debug_nibble():
    x = 14
    new_nibble = swap_nibbles(x)

    print(new_nibble)
    print(new_nibble >> 0 & 1)
    print(new_nibble >> 1 & 1)
    print(new_nibble >> 2 & 1)
    print(new_nibble >> 3 & 1)

if __name__ == "__main__":
    main()

# Put random hex numbers taking into account the restrictions of the corresponding bit.
