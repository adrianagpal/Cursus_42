#!/usr/bin/env python3

import sys


def main() -> None:
    print("=== Command Quest ===")
    print(f"Program name: {sys.argv[0]}")
    n_arg: int = len(sys.argv)
    index: int = 1

    if n_arg == 1:
        print("No arguments provided!")

    elif n_arg > 1:
        print(f"Arguments received: {n_arg - 1}")
        for arg in sys.argv[1:]:
            print(f"Argument {index}: {arg}")
            index += 1

    print(f"Total arguments: {n_arg}")


if __name__ == "__main__":
    main()
