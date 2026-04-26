#!/usr/bin/env python3

import sys


def create_inventory(items: list[str] | None = None) -> dict[str, int]:
    items_dict: dict[str, int] = {}

    if items:
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

            except IndexError:
                print(f"Error - invalid parameter {key!r}")

    return items_dict


def display_inventory(items_dict: dict[str, int]) -> None:
    if items_dict:
        print(f"Got inventory: {items_dict}")

        print(f"Item list: {list(items_dict.keys())}")

        print(f"Total quantity of the {len(items_dict.keys())} items: "
              f"{sum(items_dict.values())}")

        largest_key: str = list(items_dict.keys())[0]
        smallest_key: str = list(items_dict.keys())[0]

        for item in items_dict.keys():
            print(f"Item {item} represents "
                  f"{items_dict[item]/sum(items_dict.values()):.1%}")

            if items_dict[item] > items_dict[largest_key]:
                largest_key = item

            elif items_dict[item] < items_dict[smallest_key]:
                smallest_key = item

        print(f"Item most abundant: "
              f"{largest_key} with quantity {items_dict[largest_key]}")

        print(f"Item least abundant: "
              f"{smallest_key} with quantity {items_dict[smallest_key]}")


def main() -> None:
    print("=== Inventory System Analysis ===")
    items: list[str] = sys.argv[1:]
    items_dict: dict[str, int] = create_inventory(items)
    display_inventory(items_dict)
    items_dict.update({"magic_item": 1})
    print(f"Updated inventory: {items_dict}")


if __name__ == "__main__":
    main()
