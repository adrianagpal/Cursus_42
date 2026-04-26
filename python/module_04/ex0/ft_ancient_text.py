#!/usr/bin/env python3

import sys, typing


def main() -> None:
    n_arg: int = len(sys.argv)

    if n_arg != 2:
        print(f"Usage: {sys.argv[0]} <file>")
    else:
        print("=== Cyber Archives Recovery ===")
        print(f"Accessing file {sys.argv[1]!r}")
        try:
            f = open(sys.argv[1])
        except FileNotFoundError as fe:
            print(f"Error opening file {sys.argv[1]!r}: {fe}")
        except PermissionError as pe:
            print(f"Error opening file {sys.argv[1]!r}: {pe}")


if __name__ == "__main__":
    main()
