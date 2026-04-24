#!/usr/bin/env python3

import sys

items = sys.argv[1:]
items_dict = {}

for item in items:
    try: 
        key = item.split(":")[0] 
        value = int(item.split(":")[1])
        if key not in items_dict.keys():
            items_dict.update({key: value})
        else:
            print(f"Redundant item {key!r} - discarding")
    
    except ValueError as ve:
        print(f"Quantity error for {key!r}: {ve}")
    except IndexError as ie:
        print(f"Error - invalid parameter {key!r}")

print(f"Got inventory: {items_dict}")

print(f"Item list: {list(items_dict.keys())}")

print(f"Total quantity of the {len(items_dict.keys())} items: {sum(items_dict.values())}")

largest_key = list(items_dict.keys())[0]
smallest_key = list(items_dict.keys())[0]

for item in items_dict.keys():
    print(f"Item {item} represents {items_dict[item]/sum(items_dict.values()):.1%}")

    if items_dict[item] > items_dict[largest_key]:
        largest_key = item

    if items_dict[item] < items_dict[smallest_key]:
        smallest_key = item

print(f"Item most abundant: {largest_key} with quantity {items_dict[largest_key]}")
print(f"Item least abundant: {smallest_key} with quantity {items_dict[smallest_key]}")

    

