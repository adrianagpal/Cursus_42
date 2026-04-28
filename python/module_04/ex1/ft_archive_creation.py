#!/usr/bin/env python3

import sys, typing


#def transform_data():



def main() -> None:
    n_arg: int = len(sys.argv)
    f: typing.IO | None = None
    a: typing.IO | None = None

    if n_arg != 2:
        print(f"Usage: {sys.argv[0]} <file>\n")
    else:
        print("=== Cyber Archives Recovery ===")
        print(f"Accessing file {sys.argv[1]!r}")
        try:
            f = open(sys.argv[1])
            file_contents: str = f.read()
            print("---\n", file_contents, "\n---", sep = "\n")
        except FileNotFoundError as fe:
            print(f"Error opening file {sys.argv[1]!r}: {fe}\n")
        except PermissionError as pe:
            print(f"Error opening file {sys.argv[1]!r}: {pe}\n")
        finally:
            if f is not None:
                a = open("a.txt", "w")

                for line in file_contents:
                    a.write(line.strip("\n").join('#'))

                a_contents = open("a.txt", "r").read()
                print(f"File {sys.argv[1]!r} closed.")
                print("Transform data:", "---\n", a_contents, "\n---", sep = "\n")


if __name__ == "__main__":
    main()
